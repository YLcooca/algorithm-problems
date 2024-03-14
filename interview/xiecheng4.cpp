#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>


int main() {
  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    // 获得结点权值
    for (int j = 0; j < n; j++) {
      std::cin >> nums[j];
      nums[j] %= 2;
    }

    std::unordered_map<int, std::vector<int>> graph;
    int ans = 0;

    for (int num : nums) {
      ans ^= num;
    }

    // 奇数和偶数数量相同才能满足题意
    if (ans != 0) {
      std::cout << "No" << std::endl;
      continue;
    }

    std::unordered_map<int, int> inDegree;

    // 记录入度以及边的关系
    for (int j = 0; j < n - 1; j++) {
      int u, v;
      std::cin >> u >> v;
      u--;
      v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
      inDegree[u]++;
      inDegree[v]++;
    }

    std::queue<std::pair<int, int>> queue;

    for (const auto& entry : inDegree) {
      if (entry.second == 1) {
        queue.push({entry.first, -1});
      }
    }

    std::vector<std::pair<int, int>> operations;

    while (!queue.empty()) {
      int node = queue.front().first;
      int fa = queue.front().second;
      queue.pop();

      if (nums[node] != 0) {
        for (int next : graph[node]) {
          if (next != fa) {
            operations.push_back({node + 1, next + 1});
            inDegree[next]--;
            if (inDegree[next] == 1) {
              queue.push({next, node});
            }
            nums[node] ^= 1;
            nums[next] ^= 1;
          }
        }
      }
    }

    std::cout << "Yes" << std::endl;
    std::cout << operations.size() << std::endl;
    for (const auto& op : operations) {
      std::cout << op.first << " " << op.second << std::endl;
    }
  }

  return 0;
}
// vx公众号关注TechGuide，专业生产offer收割机，代码可能需要少量调试。