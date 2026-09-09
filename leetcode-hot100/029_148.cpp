// problem-sync:start
// #region 题目
// 题目：148. Sort List
// 顺序：029
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：67.7%
// 原题：https://leetcode.cn/problems/sort-list/
// 【题目描述】
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
// 示例 1：
// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：
// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：
// 输入：head = []
// 输出：[]
// 提示：
// - 链表中节点的数目在范围 [0, 5 * 10^4] 内
// - -10^5 <= Node.val <= 10^5
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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

// @lc app=leetcode.cn id=148 lang=cpp

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
    ListNode* sortList(ListNode* head) {

    }
};
// @lc code=end
