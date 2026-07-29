#include <queue>

using namespace std;

class Checkout {
private:
  queue<int> items;
  deque<int> decreasing_max;

public:
  Checkout() {}

  int get_max() {
    if (decreasing_max.empty()) {
      return -1;
    }
    return decreasing_max.front();
  }

  void add(int value) {
    items.push(value);
    while (!decreasing_max.empty() && value > decreasing_max.back()) {
      decreasing_max.pop_back();
    }
    decreasing_max.push_back(value);
  }

  int remove() {
    if (items.empty()) {
      return -1;
    }
    auto popped = items.front();
    items.pop();
    if (popped == decreasing_max.front()) {
      decreasing_max.pop_front();
    }
    return popped;
  }
};
