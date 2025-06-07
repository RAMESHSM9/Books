#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

//@ using forward list
template <typename T> class Stack {
private:
  struct Node {
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
  };

  Node *head;
  int numberOfElements;

public:
  Stack() : head(NULL), numberOfElements(0) {}

  void push(T value) {
    Node *temp = new Node(value);
    if (head != nullptr) {
      temp->next = head;
    }
    head = temp;
    numberOfElements++;
  }

  void pop() {
    if (head == nullptr) {
      throw std::out_of_range("Stack underflow");
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    numberOfElements--;
  }

  T top() {
    if (head == nullptr) {
      throw std::out_of_range("Stack underflow");
    }

    return head->data;
  }

  int size() { return numberOfElements; }

  bool empty() { return (head == nullptr); }
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