#include <chrono>
#include <exception>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <syncstream>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

#define sync_out std::osyncstream(std::cout)
std::exception_ptr exceptionStore; // shared memory to pass on the exception
                                   // details to other thread
std::mutex mutx;

void fun() {
  try {
    std::this_thread::sleep_for(1s);
    throw std::runtime_error("Exception throw from thread ");
  } catch (...) {
    std::lock_guard<std::mutex> lock(mutx);    // follows RAII
    exceptionStore = std::current_exception(); // current exception gives the
                                               // details of the exception
  }
}

int main() {
  thread t1(fun);

  while (!exceptionStore) {
    std::this_thread::sleep_for(2s);
    sync_out << "[main thread ]" << std::this_thread::get_id() << endl;
  }

  try {
    std::rethrow_exception(exceptionStore);
  } catch (std::exception &ex) {
    sync_out << "[main: exception] " << ex.what() << endl;
  }
  t1.join();
}