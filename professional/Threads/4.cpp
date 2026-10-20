#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

mutex m;
condition_variable cv;

bool enabled = true;
bool quit = false;

void beeper(chrono::seconds delay) {
  unique_lock lock(m);

  while (!quit) {
    cv.wait(lock, [] { return enabled || quit; });
    if (quit)
      break;
    bool interrupted =
        cv.wait_for(lock, delay, [] { return !enabled || quit; });
    if (interrupted)
      continue;
    cout << '\a' << flush;
  }
}

int main() {
  jthread worker{beeper, 3s};

  cout << "Enter: pause/resume, q: quit\n";

  string input;

  while (getline(cin, input)) {
    if (input == "q")
      break;

    if (!input.empty())
      continue;

    {
      lock_guard lock(m);
      enabled = !enabled;
    }

    cv.notify_one();
  }

  {
    lock_guard lock(m);
    quit = true;
  }

  cv.notify_one();
}
