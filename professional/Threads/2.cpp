#include <chrono>
#include <print>
#include <stop_token>
#include <thread>

using namespace std;

void beep(std::stop_token st, std::chrono::duration<int> t) {
  while (!st.stop_requested()) {
    this_thread::sleep_for(t);
    println("\a");
  }
}

int main() {
  jthread job1{beep, 3s};
  this_thread::sleep_for(100s);
  job1.request_stop();
}
