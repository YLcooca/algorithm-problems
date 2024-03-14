/**
 * @file lc96.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/unique-binary-search-trees/
 * @version 0.1
 * @date 2024-03-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
      vector<int> dp(n + 1, 0);
      dp[0] = 1;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j ) {
          dp[i] += dp[i - j] * dp[j - i];
        }
      }

      return dp[n];
    }
};