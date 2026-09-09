// problem-sync:start
// #region 题目
// 题目：15. 3Sum
// 顺序：006
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：40.6%
// 原题：https://leetcode.cn/problems/3sum/
// 【题目描述】
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i !=
//  k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复
// 的三元组。
// 注意：答案中不可以包含重复的三元组。
// 示例 1：
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：
// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
// 示例 3：
// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。
// 提示：
// - 3 <= nums.length <= 3000
// - -10^5 <= nums[i] <= 10^5
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=15 lang=cpp

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    }
};
// @lc code=end
