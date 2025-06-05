#include <iostream>
#include <thread>
using namespace std;

int counter = 0;
int main() {
  auto fun = [] {
    for (int i = 0; i < 10000; i++) {
      counter++;
    }
  };

  std::thread t1(fun);
  std::thread t2(fun);

  t1.join();
  t2.join();

  cout
      << " value of counter after threads execute [expected is 20000], but its "
      << counter << endl;
}