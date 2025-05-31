#include <cstddef>
#include <iostream>
using namespace std;

//! Logger is shared instance among all the components in an application
//! There has to be only one instance across application
class Logger {

  static Logger *loggerInstance;
  Logger() { cout << "[Logger Constructor]" << endl; }

public:
  static Logger *getInstance() {
    if (loggerInstance == NULL) {
      loggerInstance = new Logger();
    }
    return loggerInstance;
  }
  ~Logger() { cout << "[Logger Destructor]" << endl; }
};

Logger *Logger::loggerInstance = nullptr;

int main() {

  Logger *log1 = Logger::getInstance();
  cout << "Address of Logger object1 " << log1 << endl;

  Logger *log2 = Logger::getInstance();
  cout << "Address of Logger object2 " << log2 << endl;
}
