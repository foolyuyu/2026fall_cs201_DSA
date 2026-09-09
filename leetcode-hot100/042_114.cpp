// problem-sync:start
// #region 题目
// 题目：114. Flatten Binary Tree to Linked List
// 顺序：042
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：76.2%
// 原题：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
// 【题目描述】
// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// - 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指
// 针始终为 null 。
// - 展开后的单链表应该与二叉树 先序遍历 顺序相同。
// 示例 1：
// 输入：root = [1,2,5,3,4,null,6]
// 输出：[1,null,2,null,3,null,4,null,5,null,6]
// 示例 2：
// 输入：root = []
// 输出：[]
// 示例 3：
// 输入：root = [0]
// 输出：[0]
// 提示：
// - 树中结点数在范围 [0, 2000] 内
// - -100 <= Node.val <= 100
// 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
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

// @lc app=leetcode.cn id=114 lang=cpp

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
    void flatten(TreeNode* root) {

    }
};
// @lc code=end
