#include <bits/stdc++.h>
using namespace std;

//@ node structure
struct Node {
  std::shared_ptr<Node> next;
  int key;
  int value;
  std::shared_ptr<Node> previous;

  Node(int k, int v) : next(nullptr), key(k), value(v), previous(nullptr) {}
};

class DoubleLinkedList {

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;

public:
  DoubleLinkedList() : head(nullptr), tail(nullptr) {}

  std::shared_ptr<Node> push_front(int k, int v) {
    std::shared_ptr<Node> temp = make_shared<Node>(k, v);
    if (head) {
      temp->next = head;
      head->previous = temp;
      head = temp;
    } else {
      head = tail = temp;
    }
    return head;
  }

  std::pair<int, int> pop_front() {
    std::pair<int, int> res = {-1, -1};
    if (head) {
      res = {head->key, head->value};

      if (head == tail) {
        head.reset();
        tail.reset();
      } else {
        head = head->next;
        if (head) {
          head->previous.reset();
        }
      }
    }

    return res;
  }

  std::shared_ptr<Node> push_back(int k, int v) {
    std::shared_ptr<Node> temp = make_shared<Node>(k, v);
    if (tail) {
      tail->next = temp;
      temp->previous = tail;
      tail = temp;
    } else {
      head = tail = temp;
    }
    return tail;
  }

  std::pair<int, int> pop_back() {
    std::pair<int, int> res = {-1, -1};
    if (tail) {
      res = {tail->key, tail->value};

      if (head == tail) {
        head.reset();
        tail.reset();
      } else {
        tail = tail->previous;
        if (tail) {
          tail->next.reset();
        }
      }
    }

    return res;
  }

  std::pair<int, int> deleteNode(std::shared_ptr<Node> &node) {
    std::pair<int, int> res = {-1, -1};

    if (node) {
      res = {node->key, node->value};

      if (head == tail && tail == node) {
        head.reset();
        tail.reset();
      } else if (head == node) {
        head = head->next;
        if (head) {
          head->previous.reset();
        }
      } else if (tail == node) {
        tail = tail->previous;
        if (tail) {
          tail->next.reset();
        }
      } else {
        if (node->previous) {
          node->previous->next = node->next;
        }

        if (node->next) {
          node->next->previous = node->previous;
        }
      }

      node.reset();
    }

    return res;
  }

  void printList() {
    std::shared_ptr<Node> temp = head;
    while (temp) {
      cout << temp->key << ":" << temp->value << endl;
      temp = temp->next;
    }
  }
};

class LRUCacheImpl {
  DoubleLinkedList list;
  unordered_map<int, std::shared_ptr<Node>> cache;
  int capacity;

public:
  LRUCacheImpl(int capacity) {
    this->capacity = capacity;
    this->cache.clear();
  }

  //@ returns value if key exists, else -1
  int get(int key) {
    if (cache.contains(key) > 0) {
      auto &it = cache[key];
      cache.erase(key);
      std::pair<int, int> kv = list.deleteNode(it);

      std::shared_ptr<Node> newItr = list.push_back(kv.first, kv.second);
      cache[key] = newItr;
      return kv.second;
    }
    return -1;
  }

  void set(int key, int value) {
    if (cache.contains(key) > 0) {

      auto &it = cache[key];
      cache.erase(key);
      std::pair<int, int> kv = list.deleteNode(it);

    } else {
      if (cache.size() == capacity) {
        std::pair<int, int> res = list.pop_front();
        cache.erase(res.first);
      }
    }

    std::shared_ptr<Node> newItr = list.push_back(key, value);
    cache[key] = newItr;
  }
  void print() { list.printList(); }
};

int main() {
  // LRUCache lruCache(3);
  /*cout << "GET 13: " << lruCache.get(13) << endl;

  cout << "SET 8 10" << endl;
  lruCache.set(8, 10);

  cout << "SET 8 2" << endl;
  lruCache.set(8, 2);

  cout << "GET 8: " << lruCache.get(8) << endl;
  cout << "GET 10: " << lruCache.get(10) << endl;

  cout << "GET 14: " << lruCache.get(14) << endl;

  cout << "GET 15: " << lruCache.get(15) << endl;

  cout << "SET 7 1" << endl;
  lruCache.set(7, 1);

  cout << "GET 12: " << lruCache.get(12) << endl;

  cout << "GET 11: " << lruCache.get(11) << endl;

  cout << "SET 3 14" << endl;
  lruCache.set(3, 14);

  cout << "GET 3: " << lruCache.get(3) << endl;

  cout << "GET 10: " << lruCache.get(10) << endl;

  cout << "GET 1: " << lruCache.get(1) << endl;

  cout << "SET 7 14" << endl;
  lruCache.set(7, 14);

  cout << "SET 6 11" << endl;
  lruCache.set(6, 11);

  cout << "GET 7: " << lruCache.get(7) << endl;

  cout << "SET 13 6" << endl;
  lruCache.set(13, 6);

  // G 13 G 6 S 11 1 S 4 10 S 1 11 S 10 3 G 2

  cout << "GET 13: " << lruCache.get(13) << endl;

  cout << "GET 6: " << lruCache.get(6) << endl;

  cout << "SET 11 1" << endl;
  lruCache.set(11, 1);

  cout << "SET 4 10" << endl;
  lruCache.set(4, 10);

  cout << "SET 1 11" << endl;
  lruCache.set(1, 11);

  cout << "SET 10 3" << endl;
  lruCache.set(10, 3);

  cout << "GET 2: " << lruCache.get(2) << endl;*/

  // 6 1 S 2 1 S 2 2 G 2 S 1 1 S 4 1 G 2
  LRUCacheImpl lruCache(1);

  cout << "SET 2 1" << endl;
  lruCache.set(2, 1);

  cout << "SET 2 2" << endl;
  lruCache.set(2, 2);

  cout << "GET 2: " << lruCache.get(2) << endl;

  cout << "SET 1 1" << endl;
  lruCache.set(1, 1);
  lruCache.print();

  cout << "SET 4 1" << endl;
  lruCache.set(4, 1);

  cout << "GET 2: " << lruCache.get(2) << endl;
}