// problem-sync:start
// #region 题目
// 题目：108. Convert Sorted Array to Binary Search Tree
// 顺序：041
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：80.6%
// 原题：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
// 【题目描述】
// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
// 示例 1：
// 输入：nums = [-10,-3,0,5,9]
// 输出：[0,-3,9,-10,null,5]
// 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
// 示例 2：
// 输入：nums = [1,3]
// 输出：[3,1]
// 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
// 提示：
// - 1 <= nums.length <= 10^4
// - -10^4 <= nums[i] <= 10^4
// - nums 按 严格递增 顺序排列
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

// @lc app=leetcode.cn id=108 lang=cpp

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

    }
};
// @lc code=end
