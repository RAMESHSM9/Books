#include <functional>
#include <iostream>
#include <syncstream>
#include <thread>
using namespace std;

#define sync_out std::osyncstream(std::cout)

//@ Different ways of creating threads - callbacks
//! 1. Function
void fun() { sync_out << "[fun] " << std::this_thread::get_id() << endl; }

//@ 2. Function with args
void funWithArgs(int a) {

  sync_out << "[funWithArgs] a: " << a << " " << std::this_thread::get_id()
           << endl;
}

//@ 3. function objects
class funClass {
public:
  void operator()() {
    sync_out << "[funClass operator()] " << std::this_thread::get_id() << endl;
  }
};

//@ 4. function objects with args
class funClassWithArgs {
public:
  void operator()(int a) {
    sync_out << "[funClassWithArgs operator()(int)] a: " << a << " "
             << std::this_thread::get_id() << endl;
  }
};

void funCallback(int b) {
  sync_out << "[funCallback] b: " << b << " " << std::this_thread::get_id()
           << endl;
}

//@ lambdas
auto stateLessLambda = []() {
  sync_out << "[stateLessLambda ] " << std::this_thread::get_id() << endl;
};

auto stateLessLambdaWithArgs = [](int a) {
  sync_out << "[stateLessLambdaWithArgs ] a: " << a << " "
           << std::this_thread::get_id() << endl;
};

int main() {

  sync_out << "[main: start] " << std::this_thread::get_id() << endl;

  std::thread t1(fun);
  std::thread t2(funWithArgs, 10);

  funClass obj;
  std::thread t3(obj);

  funClassWithArgs obj1;
  std::thread t4(obj1, 100);

  //@ lambda
  std::thread t5(stateLessLambda);
  std::thread t6(stateLessLambdaWithArgs, 1000);

  int a = 2000;
  auto stateFullLambda = [&a]() {
    sync_out << "[stateFullLambda ] a: " << a << " "
             << std::this_thread::get_id() << endl;
  };

  auto stateFullLambdaWithArgs = [&a](int a1) {
    sync_out << "[stateFullLambdaWithArgs ] a1: " << a1 << " "
             << std::this_thread::get_id() << endl;
  };

  std::thread t7(stateFullLambda);
  std::thread t8(stateFullLambdaWithArgs, 2005);

  //@ function callback
  std::function<void(int)> fcallback = funCallback;
  std::thread t9(fcallback, 5000);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();
  t9.join();

  sync_out << "[main: end] " << std::this_thread::get_id() << endl;
}