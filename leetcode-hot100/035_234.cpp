// problem-sync:start
// #region 题目
// 题目：234. Palindrome Linked List
// 顺序：035
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：58.6%
// 原题：https://leetcode.cn/problems/palindrome-linked-list/
// 【题目描述】
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返
// 回 false 。
// 示例 1：
// 输入：head = [1,2,2,1]
// 输出：true
// 示例 2：
// 输入：head = [1,2]
// 输出：false
// 提示：
// - 链表中节点数目在范围[1, 10^5] 内
// - 0 <= Node.val <= 9
// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

// @lc app=leetcode.cn id=234 lang=cpp

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
    bool isPalindrome(ListNode* head) {

    }
};
// @lc code=end
