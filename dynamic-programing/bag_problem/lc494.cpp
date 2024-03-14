/**
 * @file lc494.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/target-sum/submissions/511842045/
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdlib>
#include <numeric>
#include <vector>


using namespace std;
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target)) {
      return 0;
    }
    if ((sum + target) % 2 == 1) {
      return 0;
    }
    int n = nums.size();
    int m = (sum + target) / 2;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[m];
  }
};