#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <syncstream>
#include <thread>
using namespace std;

#define sync_out std::osyncstream(std::cout)

template <typename Duration> class Timeout {
private:
  std::jthread jt;
  std::atomic_int32_t val{0};
  std::atomic_bool shouldStop{false};

public:
  Timeout(const Duration interval, const std::function<void(void)> callback) {
    auto timeDuration = chrono::duration_cast<chrono::milliseconds>(interval);
    auto startTime = chrono::steady_clock::now();
    jt = std::jthread([this, timeDuration, startTime, callback]() {
      while (!shouldStop.load()) {
        auto elapased = chrono::steady_clock::now() - startTime;
        if (elapased > timeDuration) {
          sync_out << "[Time has elapsed, calling callback]" << endl;
          callback();
          break;
        }
        sync_out << "[Waiting for the input] " << val.load() << endl;
        val++;
        std::this_thread::sleep_for(1s);

        // here, if there some input from
        //@ set the shouldStop to true - shouldStop.store(true)
      }
    });
  }
};

int main() {
  sync_out << "[Main Thread]" << std::this_thread::get_id() << endl;
  auto callback = [&]() {
    sync_out << "[Callback Called, after waiting for input]" << endl;
  };

  Timeout timeout(5s, [&]() {
    sync_out << "[Callback Called, after waiting for input]" << endl;
  });
  sync_out << "[Main Thread end]" << endl;
}