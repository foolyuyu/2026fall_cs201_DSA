// problem-sync:start
// #region 题目
// 题目：101. Symmetric Tree
// 顺序：037
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：63.9%
// 原题：https://leetcode.cn/problems/symmetric-tree/
// 【题目描述】
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
// 示例 1：
// 输入：root = [1,2,2,3,4,4,3]
// 输出：true
// 示例 2：
// 输入：root = [1,2,2,null,3,null,3]
// 输出：false
// 提示：
// - 树中节点数目在范围 [1, 1000] 内
// - -100 <= Node.val <= 100
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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

// @lc app=leetcode.cn id=101 lang=cpp

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
    bool isSymmetric(TreeNode* root) {

    }
};
// @lc code=end
