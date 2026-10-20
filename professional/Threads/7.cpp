#include <algorithm>
#include <atomic>

void atomicMin(std::atomic<int> &a, int b) {
  int expected = a.load();
  while (expected > b) {
    if (a.compare_exchange_strong(expected, b)) {
      break;
    }
  }
}
