#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

//@ implementing a stack using standard librar stack
//@ supporting push, pop, top, size, empty and getMin in TC O(1)
template <typename T> class Stack {
private:
  stack<T> st;
  stack<T> minStack;

public:
  Stack() {}
  void push(T value) {

    st.push(value);

    if (minStack.empty() || minStack.top() >= value) {
      minStack.push(value);
    }
  }

  void pop() {
    if (!st.empty()) {
      T ST_top = st.top();
      st.pop();

      if (!minStack.empty() && ST_top == minStack.top()) {
        minStack.pop();
      }
    } else {
      throw std::out_of_range("Stack Underflow");
    }
  }

  bool empty() const { return st.empty(); }

  int size() const { return st.size(); }

  T top() {
    if (!st.empty()) {
      return st.top();
    }
    throw std::out_of_range("Stack underflow");
  }

  T getMin() {
    if (!minStack.empty())
      return minStack.top();
    throw std::out_of_range("Stack underflow");
  }
};
int main() {
  Stack<int> st;
  st.push(2);
  cout << "[Current Min Element]" << st.getMin() << endl;
  st.push(6);
  st.push(8);
  cout << "[Current Min Element]" << st.getMin() << endl;
  st.push(1);
  cout << "[Current Min Element]" << st.getMin() << endl;
  st.push(4);
  st.push(3);
  cout << "[Current Min Element]" << st.getMin() << endl;
  st.push(6);
  cout << "[Current Min Element]" << st.getMin() << endl;

  cout << "Element at the top " << st.top() << endl;

  cout << "Size of the stack " << st.size() << endl;

  cout << "[Elements in Stack]" << endl;
  while (!st.empty()) {
    cout << st.top() << " ";
    cout << "[Current Min Element] " << st.getMin() << endl;
    st.pop();
  }
}