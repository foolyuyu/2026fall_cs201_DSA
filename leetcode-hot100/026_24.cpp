// problem-sync:start
// #region 题目
// 题目：24. Swap Nodes in Pairs
// 顺序：026
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：75.1%
// 原题：https://leetcode.cn/problems/swap-nodes-in-pairs/
// 【题目描述】
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的
// 值的情况下完成本题（即，只能进行节点交换）。
// 示例 1：
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：
// 输入：head = []
// 输出：[]
// 示例 3：
// 输入：head = [1]
// 输出：[1]
// 提示：
// - 链表中节点的数目在范围 [0, 100] 内
// - 0 <= Node.val <= 100
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// local-ide:end

// @lc app=leetcode.cn id=24 lang=cpp

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    }
};
// @lc code=end
