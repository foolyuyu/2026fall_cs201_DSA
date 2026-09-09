// problem-sync:start
// #region 题目
// 题目：239. Sliding Window Maximum
// 顺序：011
// 难度：Hard
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：50.3%
// 原题：https://leetcode.cn/problems/sliding-window-maximum/
// 【题目描述】
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可
// 以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 示例 1：
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置 最大值
// --------------- -----
// [1 3 -1] -3 5 3 6 7 3
// 1 [3 -1 -3] 5 3 6 7 3
// 1 3 [-1 -3 5] 3 6 7 5
// 1 3 -1 [-3 5 3] 6 7 5
// 1 3 -1 -3 [5 3 6] 7 6
// 1 3 -1 -3 5 [3 6 7] 7
// 示例 2：
// 输入：nums = [1], k = 1
// 输出：[1]
// 提示：
// - 1 <= nums.length <= 10^5
// - -10^4 <= nums[i] <= 10^4
// - 1 <= k <= nums.length
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=239 lang=cpp

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    }
};
// @lc code=end
