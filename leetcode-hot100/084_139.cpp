// problem-sync:start
// #region 题目
// 题目：139. Word Break
// 顺序：084
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：60.7%
// 原题：https://leetcode.cn/problems/word-break/
// 【题目描述】
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个
// 单词拼接出 s 则返回 true。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
// 示例 1：
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 示例 2：
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
// 注意，你可以重复使用字典中的单词。
// 示例 3：
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false
// 提示：
// - 1 <= s.length <= 300
// - 1 <= wordDict.length <= 1000
// - 1 <= wordDict[i].length <= 20
// - s 和 wordDict[i] 仅由小写英文字母组成
// - wordDict 中的所有字符串 互不相同
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
#include <string>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=139 lang=cpp

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

    }
};
// @lc code=end
