"""Download problem statements and judge metadata without third-party packages."""

from __future__ import annotations

import json
import re
from dataclasses import dataclass
from html.parser import HTMLParser
from urllib.parse import urlparse
from urllib.error import URLError
from urllib.request import ProxyHandler, Request, build_opener, urlopen


USER_AGENT = "Mozilla/5.0 problem-sync/1.0"


@dataclass(frozen=True)
class ProblemDetails:
    provider: str
    statement: str
    acceptance: str = ""
    cpp_template: str = ""
    python_template: str = ""
    leetcode_app: str = ""
    frontend_id: str = ""


class PlainTextHTMLParser(HTMLParser):
    """Small HTML-to-text converter tuned for online-judge statements."""

    BLOCK_START = {"p", "div", "pre", "ul", "ol", "h1", "h2", "h3", "dt", "dd"}
    BLOCK_END = BLOCK_START | {"li"}

    def __init__(self) -> None:
        super().__init__(convert_charrefs=True)
        self.parts: list[str] = []

    def handle_starttag(self, tag: str, attrs: list[tuple[str, str | None]]) -> None:
        if tag in self.BLOCK_START:
            self.parts.append("\n")
        elif tag == "li":
            self.parts.append("\n- ")
        elif tag == "br":
            self.parts.append("\n")
        elif tag == "sup":
            self.parts.append("^")
        elif tag == "sub":
            self.parts.append("_")

    def handle_endtag(self, tag: str) -> None:
        if tag in self.BLOCK_END:
            self.parts.append("\n")

    def handle_data(self, data: str) -> None:
        self.parts.append(data)

    def text(self) -> str:
        value = "".join(self.parts).replace("\xa0", " ")
        lines = [re.sub(r"[ \t]+", " ", line).strip() for line in value.splitlines()]
        value = "\n".join(lines)
        value = re.sub(r"\n{3,}", "\n\n", value)
        return value.strip()


def html_to_text(value: str) -> str:
    parser = PlainTextHTMLParser()
    parser.feed(value)
    return parser.text()


def request_text(url: str, data: bytes | None = None) -> str:
    headers = {"User-Agent": USER_AGENT}
    if data is not None:
        headers["Content-Type"] = "application/json"
    request = Request(url, data=data, headers=headers)
    try:
        response = urlopen(request, timeout=20)
    except URLError as exc:
        # Python's stdlib cannot speak socks5h proxies. A direct retry keeps the
        # synchronizer usable on machines where only HTTP traffic uses one.
        if "unknown url type: socks" not in str(exc).lower():
            raise
        clean_request = Request(url, data=data, headers=headers)
        response = build_opener(ProxyHandler({})).open(clean_request, timeout=20)
    with response:
        return response.read().decode("utf-8")


def fetch_leetcode(url: str) -> ProblemDetails:
    parsed = urlparse(url)
    slug = parsed.path.rstrip("/").split("/")[-1]
    endpoint = "https://leetcode.cn/graphql" if parsed.hostname == "leetcode.cn" else "https://leetcode.com/graphql"
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId translatedContent content stats
        codeSnippets { langSlug code }
      }
    }
    """
    payload = json.dumps(
        {"query": query, "variables": {"titleSlug": slug}}, ensure_ascii=False
    ).encode("utf-8")
    response = json.loads(request_text(endpoint, payload))
    question = response.get("data", {}).get("question")
    if not question:
        raise RuntimeError(f"LeetCode 没有返回题目：{slug}")

    snippets = {
        item.get("langSlug", ""): item.get("code", "")
        for item in question.get("codeSnippets") or []
    }
    stats = json.loads(question.get("stats") or "{}")
    return ProblemDetails(
        provider="leetcode",
        statement=html_to_text(
            question.get("translatedContent") or question.get("content") or ""
        ),
        acceptance=str(stats.get("acRate") or ""),
        cpp_template=snippets.get("cpp", ""),
        python_template=snippets.get("python3") or snippets.get("python", ""),
        leetcode_app="leetcode.cn" if parsed.hostname == "leetcode.cn" else "leetcode",
        frontend_id=str(question.get("questionFrontendId") or ""),
    )


def extract_definition_list(page: str, class_name: str) -> str:
    match = re.search(
        rf'<dl[^>]*class=["\'][^"\']*{re.escape(class_name)}[^"\']*["\'][^>]*>(.*?)</dl>',
        page,
        re.DOTALL | re.IGNORECASE,
    )
    return html_to_text(match.group(1)) if match else ""


def extract_stat(page: str, label: str) -> int | None:
    match = re.search(
        rf"<dt>\s*{re.escape(label)}\s*</dt>\s*<dd>\s*([0-9,]+)",
        page,
        re.DOTALL,
    )
    return int(match.group(1).replace(",", "")) if match else None


def fetch_openjudge(url: str) -> ProblemDetails:
    page = request_text(url)
    params = extract_definition_list(page, "problem-params")
    content = extract_definition_list(page, "problem-content")
    statement = "\n\n".join(part for part in (params, content) if part)
    if not statement:
        raise RuntimeError("OpenJudge 页面中没有找到题面")

    attempted = extract_stat(page, "尝试人数")
    accepted = extract_stat(page, "通过人数")
    acceptance = ""
    if attempted and accepted is not None:
        acceptance = f"{accepted}/{attempted} 人（{accepted / attempted * 100:.1f}%）"
    return ProblemDetails(
        provider="openjudge", statement=statement, acceptance=acceptance
    )


def fetch_problem_details(url: str) -> ProblemDetails:
    hostname = (urlparse(url).hostname or "").lower()
    if hostname in {"leetcode.cn", "leetcode.com", "www.leetcode.com"}:
        return fetch_leetcode(url)
    if hostname.endswith("openjudge.cn"):
        return fetch_openjudge(url)
    return ProblemDetails(provider="other", statement="")
