/**
 * @file lc4.cpp
 * @author Alan (248417185@qq.com)
 * @brief https://leetcode.cn/problems/median-of-two-sorted-arrays/?company_slug=xun-lei
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 奇数输出 (m + n) / 2, 偶数输出 (m + n) / 2与 (m + n) / 2 + 1 的平均值
    int m = nums1.size();
    int n = nums2.size();
    auto getKthElement = [&](int k) {
      int index1 = 0, index2 = 0;
      while (true) {
        if (index1 == m) {
          return nums2[index2 + k - 1];
        }
        if (index2 == n) {
          return nums1[index1 + k - 1];
        }
        if (k == 1) {
          return min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = min(index2 + k / 2 - 1, n - 1);
        int mid1 = nums1[newIndex1];
        int mid2 = nums2[newIndex2];
        if (mid1 <= mid2) {
          k -= newIndex1 - index1 + 1;
          index1 = newIndex1 + 1;
        } else {
          k -= newIndex2 - index2 + 1;
          index2 = newIndex2 + 1;
        }
      }
    };
    int total = m + n;
    if (total % 2 == 1) {
      return getKthElement(total / 2 + 1);
    }
    return (getKthElement(total / 2) + getKthElement(total / 2 + 1)) / 2.0;
  }
};