// problem-sync:start
// #region 题目
// 题目：206. Reverse Linked List
// 顺序：031
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：76.5%
// 原题：https://leetcode.cn/problems/reverse-linked-list/
// 【题目描述】
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// 示例 1：
// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]
// 示例 2：
// 输入：head = [1,2]
// 输出：[2,1]
// 示例 3：
// 输入：head = []
// 输出：[]
// 提示：
// - 链表中节点的数目范围是 [0, 5000]
// - -5000 <= Node.val <= 5000
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
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

// @lc app=leetcode.cn id=206 lang=cpp

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
    ListNode* reverseList(ListNode* head) {

    }
};
// @lc code=end
