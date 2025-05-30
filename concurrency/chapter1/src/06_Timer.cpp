//! Timer would call the callback after certain intervals of time and stops once
//! asked to stop explicitly
#include <chrono>
#include <functional>
#include <iostream>
#include <ostream>
#include <syncstream>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

#define sync_out std::osyncstream(std::cout)

template <typename Duration> class Timer {
public:
  typedef std::function<void(void)> callback;
  Timer(const Duration interval, const callback &cb) {

    auto value = chrono::duration_cast<chrono::milliseconds>(interval);

    sync_out << "starting Timer with the interval " << value << endl;

    jt = std::jthread([&](std::stop_token stop_token) {
      while (!stop_token.stop_requested()) {
        sync_out << "[Timer: Running callback] " << val.load() << endl;
        val++;
        cb();
        sync_out << "[Timer : sleeping]" << endl;
        std::this_thread::sleep_for(interval);
      }
      sync_out << "[Timer Exit]" << endl;
    });
  }

  void stop() { jt.request_stop(); }

private:
  std::jthread jt;
  std::atomic_int32_t val{0};
};

int main() {

  sync_out << "[main: start]" << endl;

  Timer timer(1s, [&]() { sync_out << "Callback: Running" << endl; });

  std::this_thread::sleep_for(10s);
  timer.stop();
  sync_out << "[main: end]" << endl;
}