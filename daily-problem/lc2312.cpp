/**
 * @file lc2312.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/selling-pieces-of-wood/description/
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;

class Solution {
 public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    // d[i][j] 表示高为i，宽为j的木块能卖出的最大价格
    // d[i][j] = max(d[i-mi][j-ni] + value[i], d[i][j])
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    // 初始化 i = 0或j = 0时，dp[i][j] = 0, dp[i(mi)][j(ni)] = pricei;
    for (auto& p : prices) {
      dp[p[0]][p[1]] = p[2];
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // 直接考虑分割的收益
        for (int k = 1; k < i; ++k)
          dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
        for (int k = 1; k < j; ++k)
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
      }
    }

    return dp[m][n];
  }
};