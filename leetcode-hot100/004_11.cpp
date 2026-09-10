// problem-sync:start
// #region 题目
// 题目：11. Container With Most Water
// 顺序：004
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：61.9%
// 原题：https://leetcode.cn/problems/container-with-most-water/
// 【题目描述】
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, he
// ight[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
// 说明：你不能倾斜容器。
// 示例 1：
// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49
// 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色
// 部分）的最大值为 49。
// 示例 2：
// 输入：height = [1,1]
// 输出：1
// 提示：
// - n == height.length
// - 2 <= n <= 10^5
// - 0 <= height[i] <= 10^4
// #endregion
// problem-sync:end

// 确定左边界(如果发现比左边的矮就直接跳过设为0），从右往左边界开始选择右边界，如果后一次选择，发现height没有前面的高，
// 直接pass，否则尝试计算，判断是否可以换成新的max；针对每一个左边界算出max再求max

// local-ide:start
#include <cstddef>
#include <vector>
#include <cmath>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=11 lang=cpp

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int areas = min(height[left], height[right]) * (right - left);
        for (int i = 0; i < n; ++i) {

        }
    }
};
// @lc code=end
