/**
 * @file lc1049.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/last-stone-weight-ii/description/
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sums = accumulate(stones.begin(), stones.end(), 0);
    int m = sums / 2;
    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = m; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return sums - 2 * dp[m];
  }
};