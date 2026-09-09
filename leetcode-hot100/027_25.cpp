// problem-sync:start
// #region 题目
// 题目：25. Reverse Nodes in k-Group
// 顺序：027
// 难度：Hard
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：69.9%
// 原题：https://leetcode.cn/problems/reverse-nodes-in-k-group/
// 【题目描述】
// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩
// 余的节点保持原有顺序。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
// 示例 1：
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]
// 示例 2：
// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]
// 提示：
// - 链表中的节点数目为 n
// - 1 <= k <= n <= 5000
// - 0 <= Node.val <= 1000
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
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

// @lc app=leetcode.cn id=25 lang=cpp

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
    ListNode* reverseKGroup(ListNode* head, int k) {

    }
};
// @lc code=end
