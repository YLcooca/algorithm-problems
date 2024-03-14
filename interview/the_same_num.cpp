/**
 * @file the_same_num.cpp
 * @author Alan (248417185@qq.com)
 * @brief
 * 塔子哥拿到了一个数组，他每次操作可以任选一个元素加1或者减1。他想知道，将所有元素都变成和ai
 *         相等需要操作最少多少次?你需要回答i∈[1,n]的结果，
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int main() {
  int n;
  cin >> n;
  vector<unsigned long> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  vector<unsigned long> sorted(nums);
  sort(sorted.begin(), sorted.end());
  vector<unsigned long> left(n);
  left[0] = sorted[0];
  for (int i = 1; i < n; ++i) {
    left[i] = left[i - 1] + sorted[i];
  }
  vector<unsigned long> right(n);
  right[n - 1] = sorted[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    right[i] = right[i + 1] + sorted[i];
  }
  unordered_map<int, unsigned long> map;
  for (int i = 0; i < n; ++i) {
    if (map.count(sorted[i]) == 1) {
      continue;
    }
    unsigned long leftsums = (i > 0) ? (sorted[i] * i - left[i - 1]) : 0;
    unsigned long rightsums =
        (i < n - 1) ? (right[i + 1] - sorted[i] * (n - i - 1)) : 0;
    map[sorted[i]] = leftsums + rightsums;
  }
  for (auto x : nums) {
    cout << map[x] << endl;
  }
  return 0;
}