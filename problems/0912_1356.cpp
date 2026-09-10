// problem-sync:start
// #region 题目
// 题目：1356. 根据数字二进制下 1 的数目排序
// 日期：0912
// 难度：Easy
// 标签：bit manipulation
// 平台：leetcode
// 通过率：76.6%
// 原题：https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/
// 模板指纹：f9d88fbc7a5a054209287fa563c1b0d22938c2f5a645dcc25fe4ddeb3a02de77
// 【题目描述】
// 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
// 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
// 请你返回排序后的数组。
// 示例 1：
// 输入：arr = [0,1,2,3,4,5,6,7,8]
// 输出：[0,1,2,4,8,3,5,6,7]
// 解释：[0] 是唯一一个有 0 个 1 的数。
// [1,2,4,8] 都有 1 个 1 。
// [3,5,6] 有 2 个 1 。
// [7] 有 3 个 1 。
// 按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
// 示例 2：
// 输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
// 输出：[1,2,4,8,16,32,64,128,256,512,1024]
// 解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
// 示例 3：
// 输入：arr = [10000,10000]
// 输出：[10000,10000]
// 示例 4：
// 输入：arr = [2,3,5,7,11,13,17,19]
// 输出：[2,3,5,17,7,11,13,19]
// 示例 5：
// 输入：arr = [10,100,1000,10000]
// 输出：[10,100,10000,1000]
// 提示：
// - 1 <= arr.length <= 500
// - 0 <= arr[i] <= 10^4
// #endregion
// problem-sync:end

// local-ide:start
#include <cstddef>
#include <vector>
#include <set>
#include <utility>
using namespace std;
// local-ide:end

// @lc app=leetcode.cn id=1356 lang=cpp

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        multiset<pair<int, int>> s;
        for (int i = 0; i < arr.size(); ++i) {
            int count = 0;
            int n = arr[i];
            while (n != 0) {
                if (n % 2 == 1) {
                    count++;
                }
                n /= 2;
            }
            s.insert({count, arr[i]});
        }
        vector<int> result;
        for (auto i = s.begin(); i != s.end(); ++i) {
            result.push_back(i->second);
        }
        return result;
    }
};
// @lc code=end
