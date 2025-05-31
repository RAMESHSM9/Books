#include <bits/stdc++.h>
using namespace std;

class Logger {

  Logger() { cout << "[Logger Constructor]" << endl; }

  //@ Deleting copy constructor, assignement
  //@ Explicitly deleting move copy and move assignemt
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  Logger(const Logger &&) = delete;
  Logger &operator=(const Logger &&) = delete;

public:
  static Logger &getInstance() {
    //@ Logger instance is created only once for the first when this function
    // gets called
    //@ Thread safe as well thanks to `Magic static`, c++11 or later
    static Logger loggerInstance;
    return loggerInstance;
  }

  ~Logger() { cout << "[Logger Destructor]" << endl; }
};

int main() {
  Logger &log1 = Logger::getInstance();
  std::cout << "Address of Logger object1 " << &log1 << std::endl;

  Logger &log2 = Logger::getInstance();
  std::cout << "Address of Logger object2 " << &log2 << std::endl;

  // Logger log3 = log1; - not allowed, as copy is deleted and copy would create
  // new instance which is not the goal of the singleton- similarly with other
  // ops
}