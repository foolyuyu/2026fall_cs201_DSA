// problem-sync:start
// #region 题目
// 题目：105. Construct Binary Tree from Preorder and Inorder Traversal
// 顺序：040
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：73.3%
// 原题：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 【题目描述】
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一
// 棵树的中序遍历，请构造二叉树并返回其根节点。
// 示例 1:
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]
// 示例 2:
// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]
// 提示:
// - 1 <= preorder.length <= 3000
// - inorder.length == preorder.length
// - -3000 <= preorder[i], inorder[i] <= 3000
// - preorder 和 inorder 均 无重复 元素
// - inorder 均出现在 preorder
// - preorder 保证 为二叉树的前序遍历序列
// - inorder 保证 为二叉树的中序遍历序列
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
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

// @lc app=leetcode.cn id=105 lang=cpp

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};
// @lc code=end
