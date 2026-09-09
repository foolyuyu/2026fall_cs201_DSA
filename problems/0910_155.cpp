// problem-sync:start
// #region 题目
// 题目：155. 最小栈
// 日期：0910
// 难度：Medium
// 标签：OOP, 辅助栈
// 平台：leetcode
// 通过率：62.9%
// 原题：https://leetcode.cn/problems/min-stack/
// 【题目描述】
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// - MinStack() 初始化堆栈对象。
// - void push(int value) 将元素 value 推入堆栈。
// - void pop() 删除堆栈顶部的元素。
// - int top() 获取堆栈顶部的元素。
// - int getMin() 获取堆栈中的最小元素。
// 示例 1:
// 输入：
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// 输出：
// [null,null,null,null,-3,null,0,-2]
// 解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); --> 返回 -3.
// minStack.pop();
// minStack.top(); --> 返回 0.
// minStack.getMin(); --> 返回 -2.
// 提示：
// - -2^31 <= val <= 2^31 - 1
// - pop、top 和 getMin 操作总是在 非空栈 上调用
// - push, pop, top, and getMin最多被调用 3 * 10^4 次
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=155 lang=cpp

// @lc code=start
class MinStack {
public:
    MinStack() {

    }

    void push(int value) {

    }

    void pop() {

    }

    int top() {

    }

    int getMin() {

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
