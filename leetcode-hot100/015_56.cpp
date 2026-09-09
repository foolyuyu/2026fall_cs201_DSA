// problem-sync:start
// #region 题目
// 题目：56. Merge Intervals
// 顺序：015
// 难度：Medium
// 标签：LeetCode Hot 100
// 平台：leetcode
// 通过率：54.1%
// 原题：https://leetcode.cn/problems/merge-intervals/
// 【题目描述】
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [start_i, end_i] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
// 示例 3：
// 输入：intervals = [[4,7],[1,4]]
// 输出：[[1,7]]
// 解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。
// 提示：
// - 1 <= intervals.length <= 10^4
// - intervals[i].length == 2
// - 0 <= start_i <= end_i <= 10^4
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=56 lang=cpp

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    }
};
// @lc code=end
