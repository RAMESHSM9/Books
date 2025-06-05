#include <iostream>
#include <shared_mutex>
#include <syncstream>
#include <thread>
using namespace std;

#define syn_out std::osyncstream(std::cout)
int counter = 0;
std::shared_mutex sharedMt;
int main() {

  auto reader = []() {
    for (int i = 0; i < 10; i++) {
      sharedMt.lock_shared(); //@ shared among the threads
      syn_out << "[reader] " << std::this_thread::get_id()
              << " counter : " << counter << endl;
      sharedMt.unlock_shared();
    }
  };

  auto writer = []() {
    for (int i = 0; i < 10; i++) {
      sharedMt.lock(); //@ exclusive, no thread gets the lock once acquired by a
                       // thread, until released
      counter++;
      syn_out << "[writer] " << std::this_thread::get_id()
              << " counter : " << counter << endl;
      sharedMt.unlock();
      std::this_thread::sleep_for(10s);
    }
  };

  std::thread t1(reader);
  std::thread t2(reader);
  std::thread t3(writer);
  std::thread t4(reader);
  std::thread t5(writer);
  std::thread t6(reader);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
}
