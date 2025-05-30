#include <chrono>
#include <functional>
#include <iostream>
#include <syncstream>
#include <thread>

using namespace std;
using namespace std::chrono_literals;
#define sync_out std::osyncstream(std::cout)

void fun(const std::string &str) {
  sync_out << "[fun: start] string: " << str << endl;
  std::this_thread::sleep_for(1s);
  sync_out << "[fun: end] string: " << str << endl;
}

class JthreadWrapper {
public:
  JthreadWrapper(const std::function<void(const std::string &)> &fc,
                 std::string st)
      : t(fc, st), name(st) {
    sync_out << "JthreadWrapper constructor: " << name << endl;
  }

  ~JthreadWrapper() {
    sync_out << "JthreadWrapper destructor: " << name << endl;
  }

private:
  std::jthread t;
  std::string name;
};

int main() {
  sync_out << "[main: start]" << endl;
  JthreadWrapper jt1(fun, "jt1");
  JthreadWrapper jt2(fun, "jt2");
  JthreadWrapper jt3(fun, "jt3");
  std::this_thread::sleep_for(5s);
  sync_out << "[main: end]" << endl;
}
