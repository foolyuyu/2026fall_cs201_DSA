// problem-sync:start
// #region 题目
// 题目：94. Binary Tree Inorder Traversal
// 顺序：036
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：78.3%
// 原题：https://leetcode.cn/problems/binary-tree-inorder-traversal/
// 【题目描述】
// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[1,3,2]
// 示例 2：
// 输入：root = []
// 输出：[]
// 示例 3：
// 输入：root = [1]
// 输出：[1]
// 提示：
// - 树中节点数目在范围 [0, 100] 内
// - -100 <= Node.val <= 100
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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

// @lc app=leetcode.cn id=94 lang=cpp

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
    vector<int> inorderTraversal(TreeNode* root) {

    }
};
// @lc code=end
