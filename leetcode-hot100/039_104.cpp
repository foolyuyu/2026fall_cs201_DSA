// problem-sync:start
// #region 题目
// 题目：104. Maximum Depth of Binary Tree
// 顺序：039
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：79.1%
// 原题：https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// 【题目描述】
// 给定一个二叉树 root ，返回其最大深度。
// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：3
// 示例 2：
// 输入：root = [1,null,2]
// 输出：2
// 提示：
// - 树中节点的数量在 [0, 10^4] 区间内。
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

// @lc app=leetcode.cn id=104 lang=cpp

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
    int maxDepth(TreeNode* root) {

    }
};
// @lc code=end
