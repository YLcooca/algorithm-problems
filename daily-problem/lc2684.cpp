/**
 * @file lc2684.cpp
 * @author Alan (248417185@qq.com)
 * @brief
 * https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/description/
 * @version 0.1
 * @date 2024-03-16
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 0;
    for (int j = n - 2; j >= 0; --j) {
      for (int i = 0; i < m; ++i) {
        // [i - 1][j + 1]
        if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j + 1]) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
        }
        // [i][j + 1]
        if (grid[i][j] < grid[i][j + 1]) {
          dp[i][j] = max(dp[i][j], 1 + dp[i][j + 1]);
        }
        // [i + 1][j + 1]
        if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1]) {
          dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
        }
      }
    }
    for (auto& v : dp) {
      res = max(res, v[0]);
    }
    return res;
  }
};
