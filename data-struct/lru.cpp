/**
 * @file lru.cpp
 * @author Alan (248417185@qq.com)
 * @brief LRU cache
 * @version 0.1
 * @date 2024-03-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <unordered_map>

using namespace std;
struct Node {
  int key_{0};
  int value_{0};
  Node* prev{nullptr};
  Node* next{nullptr};
  Node(int k = 0, int v = 0) : key_(k), value_(v) {}
};

// 双向循环链表
class List {
 private:
  Node* dummy_;

 public:
  List() {
    dummy_ = new Node(-1, -1);
    dummy_->prev = dummy_;
    dummy_->next = dummy_;
  }

  void push_front(Node* node) {
    node->prev = dummy_;
    node->next = dummy_->next;
    dummy_->next->prev = node;
    dummy_->next = node;
  }

  void remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = nullptr;
    node->prev = nullptr;
  }

  Node* back() { return dummy_->prev; }

  ~List() {
    Node* next = nullptr;
    if (dummy_) {
      dummy_->prev->next = nullptr;
      dummy_->prev = nullptr;
    }
    while (dummy_) {
      next = dummy_->next;
      delete dummy_;
      dummy_ = next;
    }
  }
};

class LRUCache {
 private:
  unordered_map<int, Node*> m_;
  List list_{};
  int capacity_;

 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (m_.count(key) == 0) {
      return -1;
    }
    auto node = m_[key];
    list_.remove(node);
    list_.push_front(node);
    cout << "get " << node->key_ << endl;
    return node->value_;
  }

  void put(int key, int value) {
    if (m_.count(key) == 1) {
      m_[key]->value_ = value;
      return;
    }
    // 新增结点
    Node* node = new Node(key, value);
    list_.push_front(node);
    m_[key] = node;
    // 删除超出容量的结点
    if (m_.size() > capacity_) {
      auto back_node = list_.back();
      list_.remove(back_node);
      m_.erase(back_node->key_);
      cout << "delete " << back_node->key_ << endl;
      delete back_node;
    }
  }
};

int main() {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;  // 返回 1
  cache.put(3, 3);               // 该操作会使得密钥 2 作废
  cout << cache.get(2) << endl;  // 返回 -1 (未找到)
  cache.put(4, 4);               // 该操作会使得密钥 1 作废
  cout << cache.get(1) << endl;  // 返回 -1 (未找到)
  cout << cache.get(3) << endl;  // 返回 3
  cout << cache.get(4) << endl;  // 返回 4
  return 0;
}