#include <iostream>
#include <syncstream>
#include <thread>
using namespace std;

#define sync_cout std::osyncstream(std::cout)

int main() {

  sync_cout << "[main: start]" << endl;

  std::thread t1([]() {
    sync_cout << "[stateless_lambda] " << std::this_thread::get_id() << endl;
  });

  if (t1.joinable()) {
    sync_cout << "t1 is joinable" << endl;
  }

  //@ default constructed thread are not joinable
  std::thread t2;

  if (t2.joinable()) {
    sync_cout << "t2 is joinable" << endl;
  } else {
    sync_cout << "t2 not joinable" << endl;
  }

  //@ movind thread t1 to t2
  //@ threads can only be moved, as to not allow two threads pointing to same
  // hardware thread
  t2 = std::move(t1);

  if (t1.joinable()) {
    sync_cout << "t1 is joinable" << endl;
  } else {
    sync_cout << "t1 not joinable" << endl;
  }

  if (t2.joinable()) {
    sync_cout << "t2 is joinable" << endl;
  }

  t2.join();
  sync_cout << "[main: end]" << endl;
}