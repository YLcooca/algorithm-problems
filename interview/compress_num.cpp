/**
 * @file compress_num.cpp
 * @author Alan (248417185@qq.com)
 * @brief 携程笔试
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
// 塔子哥拿到了一个数组，他想将数组内的相邻元素压缩到一起。给定的数组可能已经被压缩了一部分。
// 示例[1(2),1(1),-1(3)] -> [1(3),-1(3)]

#include <iostream>
#include <regex>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  regex re("-?\\d+\\(\\d+\\)");
  // std::regex re("([\\-\\d]+)\\((\\d+)\\)");
  auto word_begin = std::sregex_iterator(s.begin() + 1, s.end() - 1, re);
  auto word_end = std::sregex_iterator();

  // cout << distance(word_begin, word_end) << endl;

  int lastn = 0, last_times = 0;
  int curn, curtimes;
  string output{"["};
  for (auto it = word_begin; it != word_end; ++it) {
    smatch match = *it;
    auto str = match.str();
    sscanf(str.data(), "%d(%d)", &curn, &curtimes);
    if (last_times > 0) {
      if (curn == lastn) {
        last_times += curtimes;
      } else {
        // 写入
        output += to_string(lastn) + "(" + to_string(last_times) + "),";
        lastn = curn;
        last_times = curtimes;
      }
    } else {
      last_times = curtimes;
      lastn = curn;
    }
  }
  // 最后添加一次
  output += to_string(lastn) + "(" + to_string(last_times) + ")]";
  cout << output << endl;

  return 0;
}

// int main() {
//   std::string array;
//   std::getline(std::cin, array);
//   std::regex pattern("([\\-\\d]+)\\((\\d+)\\)");
//   std::sregex_iterator it(array.begin(), array.end(), pattern);
//   std::sregex_iterator end;

//   std::vector<std::string> newPairs;
//   while (it != end) {
//     newPairs.push_back((*it)[1] + "(" + (*it)[2] + ")");
//     ++it;
//   }

//   std::string result = "[";
//   int i = 0, n = newPairs.size();

//   while (i < n) {
//     std::string key = newPairs[i].substr(0, newPairs[i].find("("));
//     int val = std::stoi(
//         newPairs[i].substr(newPairs[i].find("(") + 1,
//         newPairs[i].find(")")));
//     int idx = i + 1;

//     while (idx < n && newPairs[idx].substr(0, newPairs[idx].find("(")) ==
//     key) {
//       val += std::stoi(newPairs[idx].substr(newPairs[idx].find("(") + 1,
//                                             newPairs[idx].find(")")));
//       idx++;
//     }

//     i = idx;

//     if (i != n) {
//       result += key + "(" + std::to_string(val) + "),";
//     } else {
//       result += key + "(" + std::to_string(val) + ")]";
//     }
//   }

//   std::cout << result << std::endl;

//   return 0;
// }
// vx公众号关注TechGuide，专业生产offer收割机，代码可能需要少量调试。
