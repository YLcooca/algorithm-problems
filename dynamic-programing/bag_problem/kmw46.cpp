/**
 * @file kmw46.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://kamacoder.com/problempage.php?pid=1046
 *        01背包问题
 * @version 0.1
 * @date 2024-03-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> weights(m, 0);
  vector<int> values(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> weights[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> values[i];
  }
  // 采用一维数组来做
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = n; j >= weights[i]; --j) {
      dp[j] = max(dp[j - weights[i]] + values[i], dp[j]);
    }
  }
  for (auto x : dp) {
    cout << x << " ";
  }
  cout << endl;
  // // 初始化状态
  // vector<vector<int>> dp(m, vector<int>(n + 1, 0));
  // for (int i = 0; i < m; ++i) {
  //   dp[i][0] = 0;
  // }
  // for (int i = 0; i < m; ++i) {
  //   if (weights[0] <= i) {
  //     dp[0][i] = values[0];
  //   }
  // }

  // // 递推公式：dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weights[i]] +
  // values[i]) for (int i = 1; i < m; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     if (j - weights[i] >= 0) {
  //       dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
  //     } else {
  //       dp[i][j] = dp[i - 1][j];
  //     }
  //   }
  // }

  // for (auto &v : dp) {
  //   for (auto i : v) {
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }
  // cout << dp[n][m - 1] << endl;
  return 0;
}