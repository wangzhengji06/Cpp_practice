#include <chrono>
#include <iostream>
#include <print>
#include <stop_token>
#include <thread>

using namespace std;

void beep(std::stop_token st, std::chrono::duration<int> t) {
  while (!st.stop_requested()) {
    this_thread::sleep_for(t);
    if (st.stop_requested()) {
      break;
    }
    println("\a");
  }
}

int main() {
  println("Press return for stop!");
  jthread job1{beep, 3s};

  std::cin.get();
  job1.request_stop();
}
