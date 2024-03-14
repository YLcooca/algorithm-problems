/**
 * @file lc416.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/partition-equal-subset-sum/description/
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sums = accumulate(nums.begin(), nums.end(), 0);
    if (sums % 2 == 1) return false;
    int target = sums / 2;
    vector<int> dp(target + 1, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }

    return dp[target] == target;
  }
};