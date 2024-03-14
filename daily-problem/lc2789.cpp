/**
 * @file lc2789.cpp
 * @author Alan (248417185@qq.com)
 * @brief
 * https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/description/
 *        合并后数组中的最大元素
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    // res表示整个过程中的最大值
    long long res = 0;
    // cur_sums 表示最近一次的子序列和的状态
    long long cur_sums = nums[n - 1];
    int j = n - 2;
    while (j >= 0) {
      if (nums[j] <= cur_sums) {
        cur_sums += nums[j];
      } else {
        res = max(res, cur_sums);
        cur_sums = nums[j];
      }
      --j;
    }
    // 最后再比较最后状态的cur_sums
    res = max(res, cur_sums);
    return res;
  }
};