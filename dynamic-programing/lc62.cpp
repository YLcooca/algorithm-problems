/**
 * @file lc62.cpp
 * @author Alan
 * @brief https://leetcode.cn/problems/unique-paths/description/
 * @version 0.1
 * @date 2024-03-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;
/**
 * @brief 首先确定dp数组，使用二维数组dp(i, j)表示从起始点到点(i,j)的走法
 *     因为，机器人行动时只能向右或者向下行动，故dp(i,j)=dp(i, j-1) + dp(i-1, j)
 *     必须保证i-1,j-1均大于等于0
 *
 */
// 使用二维数组进行dp
// class Solution {
//  public:
//   int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     dp[0][0] = 1;
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         if (i - 1 >= 0) {
//           dp[i][j] += dp[i - 1][j];
//         }
//         if (j - 1 >= 0) {
//           dp[i][j] += dp[i][j - 1];
//         }
//       }
//     }
//     return dp[m - 1][n - 1];
//   }
// };

// 使用滚动数组进行压缩
/* 比如3x4的矩形，其dp数组如下
 * 1 1 1 1    初始化一维数组状态dp[i]包含了上一行对应列的信息
 * 1 2 3 4    故使用dp[i] += dp[i-1]的形式更新
 * 1 3 6 10
 * 1 4 10 20
 */
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      dp[i] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i] += dp[i - 1];
      }
    }
    return dp[n - 1];
  }
};