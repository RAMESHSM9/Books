#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int counter = 0;
int main() {
  auto funWithoutLock = []() {
    for (int i = 0; i < 10000; i++) {
      counter++;
    }
  };

  std::thread t1(funWithoutLock);
  std::thread t2(funWithoutLock);

  t1.join();
  t2.join();
  cout << "[Expected counter value : 20000], but recieved " << counter << endl;

  {
    std::mutex mt; //@ exclusive and non-recursive
    counter = 0;
    auto funWithLock = [&]() {
      for (int i = 0; i < 10000; i++) {
        mt.lock();
        counter++;
        mt.unlock();
      }
    };

    std::thread t3(funWithLock);
    std::thread t4(funWithLock);

    t3.join();
    t4.join();

    cout << "[Expected counter value : 20000], and recieved " << counter
         << endl;
  }
}