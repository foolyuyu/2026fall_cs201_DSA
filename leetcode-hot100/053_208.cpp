// problem-sync:start
// #region 题目
// 题目：208. Implement Trie (Prefix Tree)
// 顺序：053
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：72.5%
// 原题：https://leetcode.cn/problems/implement-trie-prefix-tree/
// 【题目描述】
// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集
// 中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
// 请你实现 Trie 类：
// - Trie() 初始化前缀树对象。
// - void insert(String word) 向前缀树中插入字符串 word 。
// - boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经
// 插入）；否则，返回 false 。
// - boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，
// 返回 true ；否则，返回 false 。
// 示例：
// 输入
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// 输出
// [null, null, true, false, true, null, true]
// 解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple"); // 返回 True
// trie.search("app"); // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app"); // 返回 True
// 提示：
// - 1 <= word.length, prefix.length <= 2000
// - word 和 prefix 仅由小写英文字母组成
// - insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <string>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=208 lang=cpp

// @lc code=start
class Trie {
public:
    Trie() {

    }

    void insert(string word) {

    }

    bool search(string word) {

    }

    bool startsWith(string prefix) {

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
