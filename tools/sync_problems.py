#!/usr/bin/env python3
"""Refresh the course problem list and maintain a flat solution workspace.

Each problem is a source file directly under ``problems/``. Only the metadata
block at the top of an existing file may be updated; solution code is preserved.
"""

from __future__ import annotations

import argparse
import hashlib
import html
import re
import subprocess
import sys
import textwrap
import unicodedata
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import urlparse

try:
    from tools.problem_details import ProblemDetails, fetch_problem_details
except ModuleNotFoundError:  # Direct execution: python3 tools/sync_problems.py
    from problem_details import ProblemDetails, fetch_problem_details


PROJECT_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = PROJECT_ROOT / "DSA_problem_list_at_2026fall.md"
DEFAULT_OUTPUT = PROJECT_ROOT / "problems"
AUTO_START = "problem-sync:start"
AUTO_END = "problem-sync:end"
FINGERPRINT_LABEL = "模板指纹"


@dataclass(frozen=True)
class Problem:
    date: str
    number: str
    title: str
    tags: str
    difficulty: str
    url: str

    @property
    def stem(self) -> str:
        return f"{safe_component(self.date)}_{safe_component(self.number)}"

    @property
    def display_name(self) -> str:
        return f"{self.number}. {self.title}" if self.title else self.number


def strip_markup(value: str) -> str:
    value = re.sub(r"<[^>]+>", "", value)
    value = re.sub(r"\[([^]]+)]\([^)]+\)", r"\1", value)
    return html.unescape(value).strip()


def safe_component(value: str) -> str:
    value = re.sub(r"[^0-9A-Za-z_-]+", "-", value.strip())
    return value.strip("-") or "unknown"


def split_problem_name(value: str) -> tuple[str, str]:
    cleaned = strip_markup(value)
    match = re.match(r"^(?P<number>[A-Za-z]?\d+)\s*[.:：]\s*(?P<title>.*)$", cleaned)
    if match:
        return match.group("number"), match.group("title").strip()
    token, _, rest = cleaned.partition(" ")
    return token.rstrip(".:："), rest.strip()


def is_separator_row(cells: list[str]) -> bool:
    return all(re.fullmatch(r":?-{3,}:?", cell.strip()) for cell in cells)


def parse_problem_list(text: str) -> list[Problem]:
    problems: list[Problem] = []
    seen: set[tuple[str, str]] = set()

    for raw_line in text.splitlines():
        line = raw_line.strip()
        if not (line.startswith("|") and line.endswith("|")):
            continue
        cells = [cell.strip() for cell in line[1:-1].split("|")]
        if len(cells) < 5 or is_separator_row(cells):
            continue
        date, name, tags, difficulty, url = cells[:5]
        if date in {"日期", "date"} or not name or not url:
            continue
        if urlparse(url).scheme not in {"http", "https"}:
            continue

        number, title = split_problem_name(name)
        if not number:
            continue
        key = (date, number)
        if key in seen:
            continue
        seen.add(key)
        problems.append(
            Problem(
                date=date,
                number=number,
                title=title,
                tags=strip_markup(tags),
                difficulty=strip_markup(difficulty),
                url=url,
            )
        )
    return problems


def comment_prefix(language: str) -> str:
    return "//" if language == "cpp" else "#"


def metadata_block(
    problem: Problem,
    language: str,
    details: ProblemDetails | None = None,
    fingerprint: str | None = None,
) -> str:
    prefix = comment_prefix(language)
    fingerprint = fingerprint or starter_fingerprint(language, details)
    values = [
        AUTO_START,
        "#region 题目",
        f"题目：{problem.display_name}",
        f"{'顺序' if len(problem.date) == 3 else '日期'}：{problem.date}",
        f"难度：{problem.difficulty or '未标注'}",
        f"标签：{problem.tags or '未标注'}",
        f"平台：{details.provider if details else '未获取'}",
        f"通过率：{details.acceptance if details and details.acceptance else '未获取'}",
        f"原题：{problem.url}",
        f"{FINGERPRINT_LABEL}：{fingerprint}",
        "【题目描述】",
        details.statement if details and details.statement else "题面暂未下载，可打开上面的原题链接。",
        "#endregion",
        AUTO_END,
    ]
    lines: list[str] = []
    for value in values:
        for raw_line in value.replace("*/", "* /").splitlines():
            line = raw_line.strip()
            if not line:
                continue
            wrapped = wrap_comment_line(line)
            lines.extend(f"{prefix} {part}" for part in wrapped)
    return "\n".join(lines)


def display_width(value: str) -> int:
    return sum(2 if unicodedata.east_asian_width(char) in {"W", "F"} else 1 for char in value)


def wrap_comment_line(line: str, width: int = 88) -> list[str]:
    if "://" in line or display_width(line) <= width:
        return [line]
    if not any(unicodedata.east_asian_width(char) in {"W", "F"} for char in line):
        return textwrap.wrap(
            line,
            width=width,
            subsequent_indent="  " if line.startswith("- ") else "",
            break_long_words=False,
            break_on_hyphens=False,
        ) or [line]

    result: list[str] = []
    current = ""
    current_width = 0
    for char in line:
        char_width = 2 if unicodedata.east_asian_width(char) in {"W", "F"} else 1
        if current and current_width + char_width > width:
            result.append(current.rstrip())
            current = ""
            current_width = 0
        current += char
        current_width += char_width
    if current.strip():
        result.append(current.rstrip())
    return result


CPP_BODY = '''#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: 在这里编写解答。
    return 0;
}
'''


LOCAL_IDE_START = "// local-ide:start"
LOCAL_IDE_END = "// local-ide:end"

CPP_HEADERS_BY_SYMBOL = (
    (r"\bvector\s*<", "vector"),
    (r"\bstring\b", "string"),
    (r"\bunordered_map\s*<", "unordered_map"),
    (r"\bunordered_set\s*<", "unordered_set"),
    (r"(?<!unordered_)\b(?:multi)?map\s*<", "map"),
    (r"(?<!unordered_)\b(?:multi)?set\s*<", "set"),
    (r"\bstack\s*<", "stack"),
    (r"\b(?:priority_)?queue\s*<", "queue"),
    (r"\bdeque\s*<", "deque"),
    (r"\blist\s*<", "list"),
    (r"\barray\s*<", "array"),
    (r"\bfunction\s*<", "functional"),
    (r"\b(?:pair\s*<|make_pair\s*\()", "utility"),
    (r"\b(?:sort|stable_sort|reverse|lower_bound|upper_bound)\s*\(", "algorithm"),
    (r"\b(?:accumulate|iota)\s*\(", "numeric"),
    (r"\bINT_(?:MIN|MAX)\b", "climits"),
    (r"\b(?:sqrt|pow|abs)\s*\(", "cmath"),
)


def leetcode_cpp_preamble(code: str) -> str:
    """Return declarations used only by the local editor, outside @lc markers."""
    headers = ["cstddef"]
    headers.extend(
        header
        for pattern, header in CPP_HEADERS_BY_SYMBOL
        if re.search(pattern, code)
    )
    lines = [LOCAL_IDE_START]
    lines.extend(f"#include <{header}>" for header in headers)
    lines.extend(["using namespace std;"])

    if re.search(r"^\s*\*\s+struct ListNode\s*\{", code, re.MULTILINE):
        lines.extend(
            [
                "struct ListNode {",
                "    int val;",
                "    ListNode *next;",
                "    ListNode() : val(0), next(nullptr) {}",
                "    ListNode(int x) : val(x), next(nullptr) {}",
                "    ListNode(int x, ListNode *next) : val(x), next(next) {}",
                "};",
            ]
        )
    if re.search(r"^\s*\*\s+struct TreeNode\s*\{", code, re.MULTILINE):
        lines.extend(
            [
                "struct TreeNode {",
                "    int val;",
                "    TreeNode *left;",
                "    TreeNode *right;",
                "    TreeNode() : val(0), left(nullptr), right(nullptr) {}",
                "    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}",
                "    TreeNode(int x, TreeNode *left, TreeNode *right)",
                "        : val(x), left(left), right(right) {}",
                "};",
            ]
        )
    node_definition = re.search(
        r"/\*\s*(?://[^\n]*\n)?(class Node\s*\{.*?\n\};)\s*\*/",
        code,
        re.DOTALL,
    )
    if node_definition:
        lines.extend(node_definition.group(1).splitlines())
    lines.append(LOCAL_IDE_END)
    return "\n".join(lines)


def ensure_leetcode_cpp_preamble(source: str) -> str:
    if "// @lc code=start" not in source:
        return source
    preamble = leetcode_cpp_preamble(source)
    pattern = re.compile(
        rf"{re.escape(LOCAL_IDE_START)}.*?{re.escape(LOCAL_IDE_END)}",
        re.DOTALL,
    )
    if pattern.search(source):
        return pattern.sub(preamble, source, count=1)
    marker = "// @lc app="
    if marker in source:
        return source.replace(marker, f"{preamble}\n\n{marker}", 1)
    return source


PYTHON_BODY = '''import sys


def solve() -> None:
    data = sys.stdin.read().split()
    # TODO: 在这里编写解答。
    _ = data


if __name__ == "__main__":
    solve()
'''


def source_suffix(language: str) -> str:
    return ".cpp" if language == "cpp" else ".py"


def source_body(language: str) -> str:
    return CPP_BODY if language == "cpp" else PYTHON_BODY


def normalize_source_code(source: str) -> str:
    """Normalize insignificant whitespace before calculating a template hash."""
    return "\n".join(line.rstrip() for line in source.splitlines()).strip()


def starter_code(language: str, details: ProblemDetails | None) -> str:
    if details and details.provider == "leetcode":
        value = details.cpp_template if language == "cpp" else details.python_template
        if value:
            return normalize_source_code(value)
    return normalize_source_code(source_body(language))


def source_fingerprint(source: str) -> str:
    return hashlib.sha256(normalize_source_code(source).encode("utf-8")).hexdigest()


def starter_fingerprint(language: str, details: ProblemDetails | None) -> str:
    return source_fingerprint(starter_code(language, details))


def existing_fingerprint(source: str) -> str:
    match = re.search(
        rf"^(?://|#) {re.escape(FINGERPRINT_LABEL)}：([0-9a-f]{{64}})$",
        source,
        re.MULTILINE,
    )
    return match.group(1) if match else ""


def solution_code(source: str) -> str:
    leetcode_start = re.search(
        r"^\s*(?://|#) @lc code=start\s*$", source, re.MULTILINE
    )
    leetcode_end = re.search(
        r"^\s*(?://|#) @lc code=end\s*$", source, re.MULTILINE
    )
    if leetcode_start and leetcode_end and leetcode_start.end() < leetcode_end.start():
        return source[leetcode_start.end() : leetcode_end.start()]
    metadata = re.search(
        rf"^(?://|#) {re.escape(AUTO_START)}$.*?"
        rf"^(?://|#) {re.escape(AUTO_END)}$",
        source,
        re.MULTILINE | re.DOTALL,
    )
    return source[metadata.end() :] if metadata else source


def is_untouched_generated_source(path: Path) -> bool:
    source = path.read_text(encoding="utf-8")
    fingerprint = existing_fingerprint(source)
    if fingerprint:
        return source_fingerprint(solution_code(source)) == fingerprint
    # Old OpenJudge templates can be recognized exactly. Legacy LeetCode
    # files are kept when there is no reliable baseline to compare against.
    if "@lc code=start" not in source:
        language = "cpp" if path.suffix == ".cpp" else "python"
        return normalize_source_code(solution_code(source)) == normalize_source_code(
            source_body(language)
        )
    return False


def canonical_problem_url(url: str) -> str:
    parsed = urlparse(url.strip())
    return f"{parsed.netloc.lower()}{parsed.path.rstrip('/')}"


def source_problem_url(source: str) -> str:
    match = re.search(r"^(?://|#) 原题：(.+)$", source, re.MULTILINE)
    return match.group(1).strip() if match else ""


def is_managed_problem_source(path: Path) -> bool:
    return bool(
        path.is_file()
        and re.fullmatch(r"\d{4}_[0-9A-Za-z-]+\.(?:cpp|py)", path.name)
    )


def migrate_changed_dates(
    output: Path, problems: list[Problem], dry_run: bool
) -> dict[Path, Path]:
    """Move the same problem to its new date-based filename without data loss."""
    by_url = {canonical_problem_url(problem.url): problem for problem in problems}
    planned_sources: dict[Path, Path] = {}
    if not output.exists():
        return planned_sources
    for path in sorted(output.iterdir()):
        if not is_managed_problem_source(path):
            continue
        source = path.read_text(encoding="utf-8")
        if AUTO_START not in source:
            continue
        url = source_problem_url(source)
        problem = by_url.get(canonical_problem_url(url)) if url else None
        if not problem:
            continue
        target = output / f"{problem.stem}{path.suffix}"
        if target == path:
            continue
        if target.exists():
            print(
                f"提示：无法迁移 {path.name}，目标 {target.name} 已存在。",
                file=sys.stderr,
            )
            continue
        print(f"迁移：{path.name} -> {target.name}")
        planned_sources[path] = target
        if not dry_run:
            path.rename(target)
    return planned_sources


def remove_stale_untouched_sources(
    output: Path,
    problems: list[Problem],
    dry_run: bool,
    planned_migrations: dict[Path, Path],
) -> tuple[int, int]:
    """Delete obsolete empty templates and retain every edited old solution."""
    if not output.exists():
        return 0, 0
    current_stems = {problem.stem for problem in problems}
    removed = 0
    preserved = 0
    for path in sorted(output.iterdir()):
        if (
            path in planned_migrations
            or not is_managed_problem_source(path)
            or path.stem in current_stems
        ):
            continue
        source = path.read_text(encoding="utf-8")
        if AUTO_START not in source:
            continue
        if is_untouched_generated_source(path):
            print(f"删除过期空模板：{path.name}")
            removed += 1
            if not dry_run:
                path.unlink()
        else:
            print(f"保留已作答的旧题：{path.name}")
            preserved += 1
    return removed, preserved


def plugin_language(language: str) -> str:
    return "cpp" if language == "cpp" else "python3"


def render_source(
    problem: Problem, language: str, details: ProblemDetails | None
) -> str:
    block = metadata_block(problem, language, details)
    if details and details.provider == "leetcode":
        starter = starter_code(language, details)
        prefix = comment_prefix(language)
        leetcode_id = details.frontend_id or problem.number
        rendered = (
            f"{block}\n\n"
            f"{prefix} @lc app={details.leetcode_app} id={leetcode_id} "
            f"lang={plugin_language(language)}\n\n"
            f"{prefix} @lc code=start\n"
            f"{starter}\n"
            f"{prefix} @lc code=end\n"
        )
        return ensure_leetcode_cpp_preamble(rendered) if language == "cpp" else rendered
    return f"{block}\n\n{source_body(language)}"


def update_source_file(
    path: Path,
    problem: Problem,
    language: str,
    dry_run: bool,
    details: ProblemDetails | None = None,
) -> str:
    if not path.exists():
        if not dry_run:
            path.write_text(render_source(problem, language, details), encoding="utf-8")
        return "created"

    original = path.read_text(encoding="utf-8")
    if details is None:
        if language == "cpp" and "// @lc code=start" in original:
            updated = ensure_leetcode_cpp_preamble(original)
            if updated != original:
                if not dry_run:
                    path.write_text(updated, encoding="utf-8")
                return "updated"
        return "unchanged"
    fingerprint = existing_fingerprint(original) or starter_fingerprint(language, details)
    block = metadata_block(problem, language, details, fingerprint)
    prefix = re.escape(comment_prefix(language))
    pattern = re.compile(
        rf"{prefix}\s+{re.escape(AUTO_START)}.*?"
        rf"{prefix}\s+{re.escape(AUTO_END)}",
        re.DOTALL,
    )
    if pattern.search(original):
        code_without_metadata = pattern.sub("", original, count=1).strip()
        is_old_empty_template = code_without_metadata == source_body(language).strip()
        if details.provider == "leetcode" and is_old_empty_template:
            updated = render_source(problem, language, details)
        else:
            updated = pattern.sub(block, original, count=1)
        if language == "cpp" and details.provider == "leetcode":
            updated = ensure_leetcode_cpp_preamble(updated)
        if updated != original:
            if not dry_run:
                path.write_text(updated, encoding="utf-8")
            return "updated"
    return "unchanged"


def requested_languages(language: str) -> tuple[str, ...]:
    return ("cpp", "python") if language == "both" else (language,)


def code_links(problem: Problem, output: Path, planned: set[str]) -> str:
    links: list[str] = []
    for language, label in (("cpp", "C++"), ("python", "Python")):
        filename = f"{problem.stem}{source_suffix(language)}"
        if filename in planned or (output / filename).exists():
            links.append(f"[{label}](./{filename})")
    return " / ".join(links) or "—"


def existing_acceptance(problem: Problem, output: Path) -> str:
    for suffix in (".cpp", ".py"):
        path = output / f"{problem.stem}{suffix}"
        if not path.exists():
            continue
        match = re.search(
            r"^(?://|#) 通过率：(.+)$",
            path.read_text(encoding="utf-8"),
            re.MULTILINE,
        )
        if match and match.group(1) != "未获取":
            return match.group(1)
    return ""


def render_index(
    problems: list[Problem],
    output: Path,
    planned: set[str],
    details_by_stem: dict[str, ProblemDetails],
) -> str:
    lines = [
        "# 2026 Fall 题目工作区",
        "",
        "源码文件与本页由 `tools/sync_problems.py` 管理；同题换日期会保留解答并改名，旧题被替换时只删除未作答模板。",
        "",
        "| 日期 | 题目 | 难度 | 通过率 | 标签 | 代码 |",
        "| --- | --- | --- | --- | --- | --- |",
    ]
    for problem in problems:
        title = problem.display_name.replace("|", "\\|")
        difficulty = (problem.difficulty or "未标注").replace("|", "\\|")
        tags = (problem.tags or "未标注").replace("|", "\\|")
        details = details_by_stem.get(problem.stem)
        acceptance = (
            details.acceptance if details and details.acceptance else existing_acceptance(problem, output)
        ) or "—"
        lines.append(
            f"| {problem.date} | [{title}]({problem.url}) | {difficulty} | "
            f"{acceptance} | {tags} | {code_links(problem, output, planned)} |"
        )
    lines.append("")
    return "\n".join(lines)


def has_local_changes(relative_source: str) -> bool:
    for diff_args in (["git", "diff"], ["git", "diff", "--cached"]):
        result = subprocess.run(
            [*diff_args, "--quiet", "--", relative_source],
            cwd=PROJECT_ROOT,
            check=False,
        )
        if result.returncode != 0:
            return True
    return False


def refresh_source_from_upstream(source: Path, dry_run: bool) -> tuple[bool, str]:
    relative_source = source.resolve().relative_to(PROJECT_ROOT).as_posix()
    subprocess.run(
        ["git", "fetch", "upstream", "main"],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    result = subprocess.run(
        ["git", "show", f"upstream/main:{relative_source}"],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
        encoding="utf-8",
    )
    remote_text = result.stdout
    local_text = source.read_text(encoding="utf-8") if source.exists() else ""
    if remote_text == local_text:
        return False, remote_text
    if has_local_changes(relative_source):
        raise RuntimeError(
            f"{relative_source} 有本地修改，为避免覆盖，继续使用本地题单。"
        )
    if not dry_run:
        source.write_text(remote_text, encoding="utf-8")
    return True, remote_text


def synchronize(
    source: Path,
    output: Path,
    language: str,
    dry_run: bool,
    source_text: str | None = None,
    fetch_details: bool = False,
) -> tuple[int, int]:
    text = source_text if source_text is not None else source.read_text(encoding="utf-8")
    problems = parse_problem_list(text)
    if not problems:
        raise RuntimeError(f"在 {source} 中没有找到有效题目。")
    if not dry_run:
        output.mkdir(parents=True, exist_ok=True)

    planned_migrations = migrate_changed_dates(output, problems, dry_run)

    details_by_stem: dict[str, ProblemDetails] = {}
    if fetch_details:
        with ThreadPoolExecutor(max_workers=min(8, len(problems))) as executor:
            pending = {
                executor.submit(fetch_problem_details, problem.url): problem
                for problem in problems
            }
            for future in as_completed(pending):
                problem = pending[future]
                try:
                    details_by_stem[problem.stem] = future.result()
                except Exception as exc:  # One unavailable judge must not stop the sync.
                    print(
                        f"提示：{problem.display_name} 的题面获取失败（{exc}），保留现有内容。",
                        file=sys.stderr,
                    )

    created = 0
    updated = 0
    planned: set[str] = set()
    migration_targets = set(planned_migrations.values())
    for problem in problems:
        for item_language in requested_languages(language):
            filename = f"{problem.stem}{source_suffix(item_language)}"
            planned.add(filename)
            target = output / filename
            if dry_run and target in migration_targets:
                updated += 1
                continue
            state = update_source_file(
                target,
                problem,
                item_language,
                dry_run,
                details_by_stem.get(problem.stem),
            )
            created += state == "created"
            updated += state == "updated"

    remove_stale_untouched_sources(
        output, problems, dry_run, planned_migrations
    )

    index_content = render_index(problems, output, planned, details_by_stem)
    if not dry_run:
        (output / "README.md").write_text(index_content, encoding="utf-8")
    return created, updated


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="刷新 Markdown 题单，并在 problems 中维护扁平的解答文件。"
    )
    parser.add_argument("--source", type=Path, default=DEFAULT_SOURCE, help="题单路径")
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT, help="输出目录")
    parser.add_argument(
        "--language",
        choices=("cpp", "python", "both"),
        default="cpp",
        help="为新题创建的源码类型（默认：cpp）",
    )
    refresh_group = parser.add_mutually_exclusive_group()
    refresh_group.add_argument(
        "--refresh",
        dest="refresh",
        action="store_true",
        help="从 upstream/main 获取最新题单（默认行为）",
    )
    refresh_group.add_argument(
        "--no-refresh",
        dest="refresh",
        action="store_false",
        help="离线运行，只读取本地题单",
    )
    parser.set_defaults(refresh=True)
    parser.add_argument(
        "--dry-run", action="store_true", help="只显示将发生的变更，不写入文件"
    )
    return parser


def main() -> int:
    args = build_parser().parse_args()
    source = args.source.resolve()
    output = args.output.resolve()
    source_text: str | None = None

    if args.refresh:
        try:
            changed, source_text = refresh_source_from_upstream(source, args.dry_run)
            print("上游题单有更新。" if changed else "上游题单已经是最新版本。")
        except (OSError, RuntimeError, subprocess.CalledProcessError, ValueError) as exc:
            print(f"提示：刷新失败（{exc}），改用本地题单继续同步。", file=sys.stderr)

    try:
        created, updated = synchronize(
            source,
            output,
            args.language,
            args.dry_run,
            source_text,
            fetch_details=args.refresh,
        )
    except (OSError, RuntimeError, ValueError) as exc:
        print(f"同步失败：{exc}", file=sys.stderr)
        return 1

    prefix = "预计" if args.dry_run else "完成"
    print(f"{prefix}：新建 {created} 个源码文件，更新 {updated} 处题目信息。")
    print(f"题目目录：{output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
