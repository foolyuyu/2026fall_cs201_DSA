// problem-sync:start
// #region 题目
// 题目：226. Invert Binary Tree
// 顺序：045
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：82.5%
// 原题：https://leetcode.cn/problems/invert-binary-tree/
// 【题目描述】
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
// 示例 1：
// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]
// 示例 2：
// 输入：root = [2,1,3]
// 输出：[2,3,1]
// 示例 3：
// 输入：root = []
// 输出：[]
// 提示：
// - 树中节点数目范围在 [0, 100] 内
// - -100 <= Node.val <= 100
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// local-ide:end

// @lc app=leetcode.cn id=226 lang=cpp

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

    }
};
// @lc code=end
