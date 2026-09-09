// problem-sync:start
// #region 题目
// 题目：98. Validate Binary Search Tree
// 顺序：049
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：41.4%
// 原题：https://leetcode.cn/problems/validate-binary-search-tree/
// 【题目描述】
// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
// 有效 二叉搜索树定义如下：
// - 节点的左子树只包含 严格小于 当前节点的数。
// - 节点的右子树只包含 严格大于 当前节点的数。
// - 所有左子树和右子树自身必须也是二叉搜索树。
// 示例 1：
// 输入：root = [2,1,3]
// 输出：true
// 示例 2：
// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。
// 提示：
// - 树中节点数目范围在[1, 10^4] 内
// - -2^31 <= Node.val <= 2^31 - 1
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

// @lc app=leetcode.cn id=98 lang=cpp

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
    bool isValidBST(TreeNode* root) {

    }
};
// @lc code=end
