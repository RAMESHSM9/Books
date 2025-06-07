#include <bits/stdc++.h>
#include <climits>
#include <stdexcept>
using namespace std;

//@ Encoded Approach - releationship between numbers
//@ EncodedValue = 2*newValue-currentMin, if(newValue<currentMin)
//@ TC - O(1) and SC- O(N)
//@ implementing a stack using standard librar stack
//@ supporting push, pop, top, size, empty and getMin in TC O(1)
template <typename T> class Stack {
private:
  stack<T> st;
  int currentMinEle = INT_MAX;

public:
  Stack() {}
  void push(T value) {

    if (st.empty() || value > currentMinEle) {
      st.push(value);
      if (currentMinEle == INT_MAX)
        currentMinEle = value;
    } else {
      //@ store the encode = 2*newValue - currentMin
      int newMin = 2 * value - currentMinEle;
      st.push(newMin);
      currentMinEle = value;
    }
  }

  void pop() {
    if (!st.empty()) {
      int topVal = st.top();
      st.pop();

      if (topVal < currentMinEle) {
        //@ update the previous Min element
        //@ because popped element is encoded element
        int prevMin = 2 * currentMinEle - topVal;
        currentMinEle = prevMin;
      }
    } else {
      throw std::out_of_range("Stack Underflow");
    }
  }

  bool empty() const { return st.empty(); }

  int size() const { return st.size(); }

  T top() {
    if (!st.empty()) {
      if (st.top() < currentMinEle) {
        return currentMinEle;
      }
      return st.top();
    }
    throw std::out_of_range("Stack underflow");
  }

  T getMin() {
    if (!st.empty())
      return currentMinEle;
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