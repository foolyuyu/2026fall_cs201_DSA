#!/usr/bin/env python3
"""Create a flat, LeetCode-extension-compatible C++ workspace for Hot 100."""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

try:
    from tools.problem_details import ProblemDetails, fetch_problem_details
    from tools.sync_problems import Problem, refresh_source_from_upstream, update_source_file
except ModuleNotFoundError:  # Direct execution from the tools directory.
    from problem_details import ProblemDetails, fetch_problem_details
    from sync_problems import Problem, refresh_source_from_upstream, update_source_file


PROJECT_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = PROJECT_ROOT / "2026spring-cs201" / "LC_top-100-liked.md"
DEFAULT_OUTPUT = PROJECT_ROOT / "leetcode-hot100"
DIFFICULTIES = {"E": "Easy", "M": "Medium", "T": "Hard", "": "未标注"}


def title_slug(title: str) -> str:
    value = title.lower().replace("'", "")
    value = re.sub(r"[^a-z0-9]+", "-", value)
    return value.strip("-")


def parse_hot100(text: str) -> list[Problem]:
    problems: list[Problem] = []
    pattern = re.compile(r"^###\s+([EMT]?)(\d+)\.\s*(.+?)\s*$")
    for line in text.splitlines():
        match = pattern.match(line)
        if not match:
            continue
        difficulty_code, number, raw_title = match.groups()
        english_title = raw_title.split("（", 1)[0].rstrip("✅ ").strip()
        slug = title_slug(english_title)
        if not slug:
            continue
        problems.append(
            Problem(
                date=f"{len(problems) + 1:03d}",
                number=number,
                title=english_title,
                tags="LeetCode Hot 100",
                difficulty=DIFFICULTIES[difficulty_code],
                url=f"https://leetcode.cn/problems/{slug}/",
            )
        )
    return problems


def existing_acceptance(path: Path) -> str:
    if not path.exists():
        return ""
    match = re.search(r"^// 通过率：(.+)$", path.read_text(encoding="utf-8"), re.MULTILINE)
    return "" if not match or match.group(1) == "未获取" else match.group(1)


def render_index(
    problems: list[Problem], output: Path, details: dict[str, ProblemDetails]
) -> str:
    lines = [
        "# LeetCode Hot 100 C++ 工作区",
        "",
        "文件已兼容 LeetCode VS Code 扩展。打开源码后可使用 `Description`、`Test` 和 `Submit`。",
        "",
        "首次使用：安装 VS Code 推荐的 **LeetCode** 扩展，在命令面板执行 `LeetCode: Switch Endpoint` 选择 `leetcode.cn`，然后执行 `LeetCode: Sign In`。登录后，打开任意 `.cpp`，代码下方会显示 `Test` 和 `Submit`；提交结果会明确显示 Accepted 或错误类型。",
        "",
        "源码顶部的“通过率”是该题的全站通过率，不是个人完成进度；个人是否 AC 以扩展提交结果和 LeetCode 题目列表中的绿色状态为准。",
        "",
        "| 顺序 | 题目 | 难度 | 通过率 | 代码 |",
        "| --- | --- | --- | --- | --- |",
    ]
    for problem in problems:
        filename = f"{problem.stem}.cpp"
        item = details.get(problem.stem)
        acceptance = (
            item.acceptance if item and item.acceptance else existing_acceptance(output / filename)
        ) or "—"
        lines.append(
            f"| {problem.date} | [{problem.display_name}]({problem.url}) | "
            f"{problem.difficulty} | {acceptance} | [C++](./{filename}) |"
        )
    lines.append("")
    return "\n".join(lines)


def sync_hot100(
    source_text: str,
    output: Path,
    dry_run: bool,
    update_details: bool,
) -> tuple[int, int, int]:
    problems = parse_hot100(source_text)
    if not problems:
        raise RuntimeError("没有在 Hot 100 文档中找到题目标题。")
    if not dry_run:
        output.mkdir(parents=True, exist_ok=True)

    to_fetch = [
        problem
        for problem in problems
        if update_details or not (output / f"{problem.stem}.cpp").exists()
    ]
    details: dict[str, ProblemDetails] = {}
    failed = 0
    if to_fetch:
        print(f"正在获取 {len(to_fetch)} 道 LeetCode 题面和官方 C++ 模板……")
        with ThreadPoolExecutor(max_workers=min(6, len(to_fetch))) as executor:
            pending = {
                executor.submit(fetch_problem_details, problem.url): problem
                for problem in to_fetch
            }
            for future in as_completed(pending):
                problem = pending[future]
                try:
                    item = future.result()
                    if item.frontend_id and item.frontend_id != problem.number:
                        raise RuntimeError(
                            f"题号不匹配：期望 {problem.number}，得到 {item.frontend_id}"
                        )
                    details[problem.stem] = item
                except Exception as exc:
                    failed += 1
                    print(
                        f"提示：{problem.display_name} 获取失败（{exc}）。",
                        file=sys.stderr,
                    )

    created = 0
    updated = 0
    for problem in problems:
        state = update_source_file(
            output / f"{problem.stem}.cpp",
            problem,
            "cpp",
            dry_run,
            details.get(problem.stem),
        )
        created += state == "created"
        updated += state == "updated"

    if not dry_run:
        (output / "README.md").write_text(
            render_index(problems, output, details), encoding="utf-8"
        )
    return created, updated, failed


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="同步 LeetCode Hot 100 C++ 工作区。")
    parser.add_argument("--source", type=Path, default=DEFAULT_SOURCE, help="Hot 100 文档")
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT, help="输出目录")
    parser.add_argument(
        "--update-details",
        action="store_true",
        help="重新下载所有题面和通过率；默认只下载新题",
    )
    refresh_group = parser.add_mutually_exclusive_group()
    refresh_group.add_argument("--refresh", dest="refresh", action="store_true")
    refresh_group.add_argument("--no-refresh", dest="refresh", action="store_false")
    parser.set_defaults(refresh=True)
    parser.add_argument("--dry-run", action="store_true")
    return parser


def main() -> int:
    args = build_parser().parse_args()
    source = args.source.resolve()
    source_text: str | None = None
    if args.refresh:
        try:
            changed, source_text = refresh_source_from_upstream(source, args.dry_run)
            print("上游 Hot 100 文档有更新。" if changed else "上游 Hot 100 文档已是最新版本。")
        except (OSError, RuntimeError, subprocess.CalledProcessError, ValueError) as exc:
            print(f"提示：刷新失败（{exc}），改用本地文档。", file=sys.stderr)
    if source_text is None:
        source_text = source.read_text(encoding="utf-8")

    try:
        created, updated, failed = sync_hot100(
            source_text,
            args.output.resolve(),
            args.dry_run,
            args.update_details,
        )
    except (OSError, RuntimeError, ValueError) as exc:
        print(f"同步失败：{exc}", file=sys.stderr)
        return 1

    prefix = "预计" if args.dry_run else "完成"
    print(
        f"{prefix}：新建 {created} 个文件，更新 {updated} 个文件，"
        f"题面获取失败 {failed} 道。"
    )
    print(f"Hot 100 目录：{args.output.resolve()}")
    return 0 if failed == 0 else 2


if __name__ == "__main__":
    raise SystemExit(main())
