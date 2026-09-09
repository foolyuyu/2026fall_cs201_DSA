// problem-sync:start
// #region 题目
// 题目：437. Path Sum III
// 顺序：047
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：49.3%
// 原题：https://leetcode.cn/problems/path-sum-iii/
// 【题目描述】
// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSu
// m 的 路径 的数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点
// 到子节点）。
// 示例 1：
// 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// 输出：3
// 解释：和等于 8 的路径有 3 条，如图所示。
// 示例 2：
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：3
// 提示:
// - 二叉树的节点个数的范围是 [0,1000]
// - -10^9 <= Node.val <= 10^9
// - -1000 <= targetSum <= 1000
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

// @lc app=leetcode.cn id=437 lang=cpp

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
    int pathSum(TreeNode* root, int targetSum) {

    }
};
// @lc code=end
