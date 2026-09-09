import tempfile
import unittest
from pathlib import Path

from tools.problem_details import ProblemDetails, html_to_text
from tools.sync_problems import (
    build_parser,
    display_width,
    ensure_leetcode_cpp_preamble,
    metadata_block,
    parse_problem_list,
    render_source,
    synchronize,
    update_source_file,
)
from tools.sync_hot100 import parse_hot100, title_slug


SAMPLE = """\
| 日期 | 问题编号与名称 | 标签 | 难度 | 链接 |
| --- | --- | --- | --- | --- |
| 0910 | <mark>155.最小栈</mark> | OOP, 辅助栈 | Medium | https://example.com/155 |
| 0911 | 1356.根据数字二进制下 1 的数目排序 | bit | Easy | https://example.com/1356 |
| 0912 | | | Medium | |
"""


class SyncProblemsTest(unittest.TestCase):
    def test_defaults_to_cpp_and_refresh(self) -> None:
        args = build_parser().parse_args([])
        self.assertEqual(args.language, "cpp")
        self.assertTrue(args.refresh)

    def test_parse_problem_list(self) -> None:
        problems = parse_problem_list(SAMPLE)
        self.assertEqual(len(problems), 2)
        self.assertEqual(problems[0].number, "155")
        self.assertEqual(problems[0].title, "最小栈")
        self.assertEqual(problems[0].stem, "0910_155")

    def test_flat_sync_never_overwrites_solution_code(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            source = root / "list.md"
            output = root / "problems"
            source.write_text(SAMPLE, encoding="utf-8")

            synchronize(source, output, "cpp", False)
            solution = output / "0910_155.cpp"
            self.assertTrue(solution.exists())
            self.assertFalse((output / "0910_155").exists())
            custom_code = solution.read_text(encoding="utf-8").replace(
                "// TODO: 在这里编写解答。", "cout << 42 << '\\n';"
            )
            solution.write_text(custom_code, encoding="utf-8")
            source.write_text(SAMPLE.replace("Medium", "Hard"), encoding="utf-8")

            changed_problem = parse_problem_list(source.read_text(encoding="utf-8"))[0]
            update_source_file(
                solution,
                changed_problem,
                "cpp",
                False,
                ProblemDetails(provider="leetcode", statement="完整题面", acceptance="50%"),
            )
            updated = solution.read_text(encoding="utf-8")
            self.assertIn("难度：Hard", updated)
            self.assertIn("cout << 42", updated)
            self.assertIn("[C++](./0910_155.cpp)", (output / "README.md").read_text())

    def test_html_statement_conversion(self) -> None:
        text = html_to_text("<p>输入 <code>n</code></p><ul><li>1 &lt;= n</li></ul>")
        self.assertIn("输入 n", text)
        self.assertIn("- 1 <= n", text)

    def test_generated_comments_are_compact_and_wrapped(self) -> None:
        problem = parse_problem_list(SAMPLE)[0]
        block = metadata_block(
            problem,
            "cpp",
            ProblemDetails(provider="openjudge", statement="第一段\n\n" + "很长的中文题面" * 30),
        )
        self.assertNotIn("\n//\n", block)
        for line in block.splitlines():
            if "://" not in line:
                self.assertLessEqual(display_width(line), 92)

    def test_hot100_heading_and_slug(self) -> None:
        problems = parse_hot100(
            "### E1. Two Sum（两数之和）✅\n"
            "### 31. Next Permutation（下一个排列）✅\n"
        )
        self.assertEqual(len(problems), 2)
        self.assertEqual(problems[0].url, "https://leetcode.cn/problems/two-sum/")
        self.assertEqual(problems[1].stem, "002_31")
        self.assertEqual(title_slug("Pascal's Triangle"), "pascals-triangle")

    def test_python_is_optional(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            source = root / "list.md"
            output = root / "problems"
            source.write_text(SAMPLE, encoding="utf-8")
            synchronize(source, output, "python", False)
            self.assertTrue((output / "0910_155.py").exists())
            self.assertFalse((output / "0910_155.cpp").exists())

    def test_leetcode_refresh_preserves_code_between_markers(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            path = Path(temp_dir) / "001_1.cpp"
            problem = parse_problem_list(SAMPLE)[0]
            first = ProblemDetails(
                provider="leetcode",
                statement="旧题面",
                acceptance="40%",
                cpp_template="class Solution { /* starter */ };",
                leetcode_app="leetcode.cn",
                frontend_id="155",
            )
            update_source_file(path, problem, "cpp", False, first)
            path.write_text(
                path.read_text(encoding="utf-8").replace("/* starter */", "int answer = 42;"),
                encoding="utf-8",
            )
            second = ProblemDetails(
                provider="leetcode",
                statement="新题面",
                acceptance="41%",
                cpp_template="class Solution { /* changed starter */ };",
                leetcode_app="leetcode.cn",
                frontend_id="155",
            )
            update_source_file(path, problem, "cpp", False, second)
            content = path.read_text(encoding="utf-8")
            self.assertIn("int answer = 42;", content)
            self.assertNotIn("changed starter", content)
            self.assertIn("通过率：41%", content)
            self.assertIn("新题面", content)

    def test_leetcode_cpp_gets_local_ide_support_outside_submit_markers(self) -> None:
        source = """// @lc app=leetcode.cn id=1 lang=cpp

// @lc code=start
class Solution {
public:
    vector<int> answer(vector<int>& nums) { return nums; }
};
// @lc code=end
"""
        updated = ensure_leetcode_cpp_preamble(source)
        self.assertIn("#include <vector>", updated)
        self.assertIn("using namespace std;", updated)
        self.assertLess(updated.index("// local-ide:end"), updated.index("// @lc app="))
        submitted = updated.split("// @lc code=start\n", 1)[1].split(
            "// @lc code=end", 1
        )[0]
        self.assertNotIn("#include", submitted)

    def test_leetcode_starter_removes_trailing_whitespace(self) -> None:
        problem = parse_problem_list(SAMPLE)[0]
        rendered = render_source(
            problem,
            "cpp",
            ProblemDetails(
                provider="leetcode",
                statement="题面",
                cpp_template="class Solution {  \n    \n};  ",
                leetcode_app="leetcode.cn",
                frontend_id="155",
            ),
        )
        self.assertTrue(all(line == line.rstrip() for line in rendered.splitlines()))

    def test_leetcode_linked_list_gets_local_definition(self) -> None:
        source = """// @lc app=leetcode.cn id=2 lang=cpp
// @lc code=start
/**
 * struct ListNode {
 * };
 */
class Solution { ListNode* solve(ListNode* head) { return head; } };
// @lc code=end
"""
        updated = ensure_leetcode_cpp_preamble(source)
        self.assertIn("struct ListNode {", updated)
        self.assertLess(updated.index("struct ListNode {"), updated.index("// @lc app="))

    def test_leetcode_custom_node_comment_gets_local_definition(self) -> None:
        source = """// @lc app=leetcode.cn id=138 lang=cpp
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
};
*/
class Solution { Node* solve(Node* head) { return head; } };
// @lc code=end
"""
        updated = ensure_leetcode_cpp_preamble(source)
        self.assertEqual(updated.count("class Node {"), 2)
        self.assertLess(updated.index("class Node {"), updated.index("// @lc app="))


if __name__ == "__main__":
    unittest.main()
