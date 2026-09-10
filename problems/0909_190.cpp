// problem-sync:start
// #region 题目
// 题目：190. 颠倒二进制位
// 日期：0909
// 难度：Easy
// 标签：bit manipulation
// 平台：leetcode
// 通过率：75.0%
// 原题：https://leetcode.cn/problems/reverse-bits/
// 模板指纹：6be1f7281ace495812c5465e01fc1621bd8e77125ca9f23dbd70a2c0bf6beba9
// 【题目描述】
// 颠倒给定的 32 位有符号整数的二进制位。
// 示例 1：
// 输入：n = 43261596
// 输出：964176192
// 解释：
// 整数
// 二进制
// 43261596
// 00000010100101000001111010011100
// 964176192
// 00111001011110000010100101000000
// 示例 2：
// 输入：n = 2147483644
// 输出：1073741822
// 解释：
// 整数
// 二进制
// 2147483644
// 01111111111111111111111111111100
// 1073741822
// 00111111111111111111111111111110
// 提示：
// - 0 <= n <= 2^31 - 2
// - n 为偶数
// 进阶: 如果多次调用这个函数，你将如何优化你的算法？
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <queue>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=190 lang=cpp

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        queue<int> q;
        for(int i = 0; i < 32; ++i) {
            q.push(n % 2);
            n /= 2;
        }
        int result = 0;
        while(!q.empty()) {
            result = result * 2 + q.front();
            q.pop();
        }
        return result;
    }
};
// @lc code=end
