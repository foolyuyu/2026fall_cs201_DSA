// problem-sync:start
// #region 题目
// 题目：230. Kth Smallest Element in a BST
// 顺序：050
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：79.8%
// 原题：https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
// 【题目描述】
// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（
// k 从 1 开始计数）。
// 示例 1：
// 输入：root = [3,1,4,null,2], k = 1
// 输出：1
// 示例 2：
// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3
// 提示：
// - 树中的节点数为 n 。
// - 1 <= k <= n <= 10^4
// - 0 <= Node.val <= 10^4
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何
// 优化算法？
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

// @lc app=leetcode.cn id=230 lang=cpp

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
    int kthSmallest(TreeNode* root, int k) {

    }
};
// @lc code=end
