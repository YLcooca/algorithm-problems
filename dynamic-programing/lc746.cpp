/**
 * @file lc746.cpp
 * @author Alan
 * @brief https://leetcode.cn/problems/min-cost-climbing-stairs/
 * @version 0.1
 * @date 2024-03-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
          dp[i] = min(dp[i-1] + cost[i - 1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};