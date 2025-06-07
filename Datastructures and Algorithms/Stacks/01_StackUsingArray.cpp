#include <bits/stdc++.h>
using namespace std;

//@ using arrays - meaning, we need to accept the static size from user
#define MAX_SIZE 10

template <typename T> class Stack {
private:
  T arr[MAX_SIZE];
  int _top = -1;

public:
  Stack() {}

  //@ check for overflow
  void push(T value) {
    if (_top >= MAX_SIZE) {
      throw std::out_of_range("[Stack overflow]");
    }
    arr[++_top] = value;
  }

  // # check for underflow
  void pop() {
    if (_top <= -1) {
      throw std::out_of_range("[Stack underflow]");
    }
    --_top;
  }

  //@ check for underflow
  int top() {
    if (_top <= -1) {
      throw std::out_of_range("[Stack underflow]");
    }
    return arr[_top];
  }

  bool empty() { return (_top == -1); }

  int size() { return (_top + 1); }
};

int main() {
  Stack<int> st;
  st.push(10);
  st.push(100);
  cout << "Element at the top " << st.top() << endl;

  cout << "Size of the stack " << st.size() << endl;

  cout << "[Elements in Stack]" << endl;
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}