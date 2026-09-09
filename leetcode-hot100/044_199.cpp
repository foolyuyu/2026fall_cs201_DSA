// problem-sync:start
// #region 题目
// 题目：199. Binary Tree Right Side View
// 顺序：044
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：73.8%
// 原题：https://leetcode.cn/problems/binary-tree-right-side-view/
// 【题目描述】
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所
// 能看到的节点值。
// 示例 1：
// 输入：root = [1,2,3,null,5,null,4]
// 输出：[1,3,4]
// 解释：
// 示例 2：
// 输入：root = [1,2,3,4,null,null,null,5]
// 输出：[1,3,4,5]
// 解释：
// 示例 3：
// 输入：root = [1,null,3]
// 输出：[1,3]
// 示例 4：
// 输入：root = []
// 输出：[]
// 提示:
// - 二叉树的节点个数的范围是 [0,100]
// - -100 <= Node.val <= 100
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

// @lc app=leetcode.cn id=199 lang=cpp

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
    vector<int> rightSideView(TreeNode* root) {

    }
};
// @lc code=end
