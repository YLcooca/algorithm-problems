/**
 * @file lc1793.cpp
 * @author Alan (248417185@qq.com)
 * @brief
 * https://leetcode.cn/problems/maximum-score-of-a-good-subarray/description/
 * @version 0.1
 * @date 2024-03-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <vector>

using namespace std;
class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int i = k, j = k;
    unsigned long ans = nums[k];
    int min_h = nums[k];
    for (int t = 0; t < n - 1; ++t) {
      if (j == n - 1 || i && nums[i - 1] > nums[j + 1]) {
        min_h = min(min_h, nums[--i]);
      } else {
        min_h = min(min_h, nums[++j]);
      }
      ans = max(ans, min_h * (j - i + 1UL));
    }
    return ans;
  }
};