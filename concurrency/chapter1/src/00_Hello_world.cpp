#include <iostream>
#include <syncstream>
#include <thread>
using namespace std;

#define sync_out std::osyncstream(std::cout)

int main() {
  sync_out << "[Main] Hello world " << std::this_thread::get_id() << endl;
}