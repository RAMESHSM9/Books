//! TLS - Thread local storage - OS provides utility for Thread to have its
//! local variables which are not shared with other thread
#include <iostream>
#include <syncstream>
#include <thread>

using namespace std;
using namespace std::chrono_literals;
#define sync_out std::osyncstream(std::cout)

thread_local int val = 0; // each thread will have the val variable created
                          // within its memory

void setValue(int v) { val = v; }

void printValue() {
  sync_out << std::this_thread::get_id() << " val " << val << endl;
}

void multiplyBy2(int arg) {
  setValue(arg);
  val *= 2;
  printValue();
}

int main() {

  val = 1; // main threads local variable
  sync_out << "[main: start] val " << val << endl;
  std::jthread jt1(multiplyBy2, 1);
  std::jthread jt2(multiplyBy2, 2);
  std::jthread jt3(multiplyBy2, 3);

  std::this_thread::sleep_for(2s);
  sync_out << "[main: start] val: " << val << endl;
}
