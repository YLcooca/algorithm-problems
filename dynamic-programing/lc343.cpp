/**
 * @file lc343.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/integer-break/description/
 * @version 0.1
 * @date 2024-03-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    // dp[i] 为i可以拆分的最大乘积
    // dp[i] = max(j * (i - j), j * dp[i - j]) j = 1...i-2
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j < i - 1; ++j) {
        dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
      }
    }

    return dp[n];
  }
};