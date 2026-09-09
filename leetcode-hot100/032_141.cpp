// problem-sync:start
// #region 题目
// 题目：141. Linked List Cycle
// 顺序：032
// 难度：Easy
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：55.1%
// 原题：https://leetcode.cn/problems/linked-list-cycle/
// 【题目描述】
// 给你一个链表的头节点 head ，判断链表中是否有环。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定
// 链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注
// 意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
// 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。
// 示例 2：
// 输入：head = [1,2], pos = 0
// 输出：true
// 解释：链表中有一个环，其尾部连接到第一个节点。
// 示例 3：
// 输入：head = [1], pos = -1
// 输出：false
// 解释：链表中没有环。
// 提示：
// - 链表中节点的数目范围是 [0, 10^4]
// - -10^5 <= Node.val <= 10^5
// - pos 为 -1 或者链表中的一个 有效索引 。
// 进阶：你能用 O(1)（即，常量）内存解决此问题吗？
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

// @lc app=leetcode.cn id=141 lang=cpp

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

    }
};
// @lc code=end
