/**
 * @file lc63.cpp
 * @author Alan
 * @brief https://leetcode.cn/problems/unique-paths-ii/
 * @version 0.1
 * @date 2024-03-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;

// 采用二维数组进行dp，并且遇到障碍物时表明不可达
// class Solution {
//  public:
//   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int m = obstacleGrid.size();
//     int n = obstacleGrid[0].size();

//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     dp[0][0] = 1;
//     // 初始化第一行和第一列的路径情况
//     for (int j = 1; j < n; ++j) {
//       if (obstacleGrid[0][j] == 1) {
//         dp[0][j] = 0;
//       } else {
//         dp[0][j] = dp[0][j - 1];
//       }
//     }
//     for (int i = 1; i < m; ++i) {
//       if (obstacleGrid[i][0] == 1) {
//         dp[i][0] = 0;
//       } else {
//         dp[i][0] = dp[i - 1][0];
//       }
//     }

//     for (int i = 1; i < m; ++i) {
//       for (int j = 1; j < n; ++j) {
//         if (obstacleGrid[i][j] == 1) {
//           dp[i][j] = 0;
//         } else {
//           dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//       }
//     }

//     return dp[m - 1][n - 1];
//   }
// };

// 尝试用一维数组
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0] == 1) {
      return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    // 初始化第一行的情况
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[0][j] == 1) {
        dp[j] = 0;
      } else {
        dp[j] = dp[j - 1];
      }
    }
    int lastdp0 = 1;
    for (int i = 1; i < m; ++i) {
      // 更新dp[0]的值
      if (obstacleGrid[i][0] == 1) {
        dp[0] = 0;
        lastdp0 = 0;
      } else {
        dp[0] = lastdp0;
      }
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[j] = 0;
        } else {
          dp[j] += dp[j - 1];
        }
      }
    }

    return dp[n - 1];
  }
};