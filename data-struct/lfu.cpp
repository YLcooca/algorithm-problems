/**
 * @file lfu.cpp
 * @author Alan (248417185@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-03-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <unordered_map>

using namespace std;

struct Node {
  int key, value, freq = 1;
  Node *prev, *next;
  Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LFUCache {
 private:
  int min_freq;
  int capacity;

  unordered_map<int, Node*> key_to_node;
  unordered_map<int, Node*> freq_to_dummy;

  Node* get_node(int key) {
    auto it = key_to_node.find(key);
    if (it == key_to_node.end()) {
      return nullptr;
    }
    auto node = it->second;
    remove(node);
    auto dummy = freq_to_dummy[node->freq];
    if (dummy->prev == dummy) {
      freq_to_dummy.erase(node->freq);
      delete dummy;
      if (min_freq == node->freq) {
        min_freq++;
      }
    }
    push_front(++node->freq, node);
    return node;
  }

  // 创建双向链表
  Node* new_list() {
    auto dummy = new Node();
    dummy->prev = dummy;
    dummy->next = dummy;
    return dummy;
  }

  // 在链表头添加一个节点
  void push_front(int freq, Node* x) {
    auto it = freq_to_dummy.find(freq);
    if (it == freq_to_dummy.end()) {
      it = freq_to_dummy.emplace(freq, new_list()).first;
    }
    auto dummy = it->second;
    x->prev = dummy;
    x->next = dummy->next;
    x->prev->next = x;
    x->next->prev = x;
  }

  // 删除一个结点
  void remove(Node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
  }

 public:
  LFUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto node = get_node(key);
    return node ? node->value : -1;
  }

  void put(int key, int value) {
    auto node = get_node(key);
    if (node) {
      node->value = value;
      return;
    }
    if (key_to_node.size() == capacity) {
      auto dummy = freq_to_dummy[min_freq];
      auto back_node = dummy->prev;
      key_to_node.erase(back_node->key);
      remove(back_node);
      delete back_node;
      if (dummy->prev == dummy) {
        freq_to_dummy.erase(min_freq);
        delete dummy;
      }
    }
    key_to_node[key] = node = new Node(key, value);
    push_front(1, node);
    min_freq = 1;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */