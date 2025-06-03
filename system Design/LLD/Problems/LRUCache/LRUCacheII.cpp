#include <bits/stdc++.h>
using namespace std;
// node in the list would have key, value
struct Node {
  int key;
  int value;
  Node(int k, int v) : key(k), value(v) {}
};

class LRUCacheImpl {
  unordered_map<int, list<Node>::iterator> lookUpTable;
  list<Node> elementsInLRUOrder;
  int capacity;

public:
  LRUCacheImpl(int cap) : capacity(cap) {}

  int get(int key) {
    //@key exists
    if (lookUpTable.count(key) > 0) {
      auto it = lookUpTable[key];
      int k = it->key;
      int v = it->value;

      //@ delete the exist element from current location
      elementsInLRUOrder.erase(it);
      lookUpTable.erase(k);

      Node node(k, v);
      elementsInLRUOrder.push_front(node);
      lookUpTable.insert(make_pair(k, elementsInLRUOrder.begin()));

      return v;
    }
    return -1;
  }

  void set(int key, int value) {
    if (lookUpTable.count(key) > 0) {
      auto it = lookUpTable[key];
      int k = it->key;
      int v = it->value;

      elementsInLRUOrder.erase(it);
      lookUpTable.erase(k);
    } else {
      if (capacity == lookUpTable.size()) {
        //@ element from the end needs to removed
        auto it = elementsInLRUOrder.back();
        int k = it.key;
        int v = it.value;

        elementsInLRUOrder.pop_back();
        lookUpTable.erase(k);
      }
    }

    Node node(key, value);
    elementsInLRUOrder.push_front(node);
    lookUpTable.insert(make_pair(key, elementsInLRUOrder.begin()));
  }

  void print() {
    cout << "[Printing List start]" << endl;
    for (auto it = elementsInLRUOrder.begin(); it != elementsInLRUOrder.end();
         ++it) {
      cout << it->key << " " << it->value << endl;
    }
    cout << "[Printing List end]" << endl;
  }
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
  // 6 1 S 2 1 S 2 2 G 2 S 1 1 S 4 1 G 2
  /*LRUCacheImpl lruCache(1);

  cout << "SET 2 1" << endl;
  lruCache.set(2, 1);

  cout << "SET 2 2" << endl;
  lruCache.set(2, 2);

  cout << "GET 2: " << lruCache.get(2) << endl;

  cout << "SET 1 1" << endl;
  lruCache.set(1, 1);

  cout << "SET 4 1" << endl;
  lruCache.set(4, 1);
  lruCache.print();

  cout << "GET 2: " << lruCache.get(2) << endl;*/

  // 59 7 S 2 1 S 1 10 S 8 13 G 12 S 2 8 G 11 G 7 S 14 7 S 12 9 S 7 10 G 11 S 9
  // 3 S 14 15 G 15 G 9 S 4 13 G 3 S 13 7 G 2 S 5 9 G 6 G 13 S 4 5 S 3 2 S 4 12
  // G 13 G 7 S 9 7 G 3 G 6 G 2 S 8 4 S 8 9 S 1 4 S 2 9 S 8 8 G 13 G 3 G 13 G 6
  // S 3 8 G 14 G 4 S 5 6 S 10 15 G 12 S 13 5 S 10 9 S 3 12 S 14 15 G 4 S 10 5 G
  // 5 G 15 S 7 6 G 1 S 5 12 S 1 6 S 11 8

  LRUCacheImpl lruCache(7);
  cout << "SET 2 1" << endl;
  lruCache.set(2, 1);

  cout << "SET 1 10" << endl;
  lruCache.set(1, 10);

  cout << "SET 8 13" << endl;
  lruCache.set(8, 13);

  cout << "GET 12: " << lruCache.get(12) << endl;

  cout << "SET 2 8" << endl;
  lruCache.set(2, 8);

  cout << "GET 11: " << lruCache.get(11) << endl;

  cout << "GET 7: " << lruCache.get(7) << endl;
}