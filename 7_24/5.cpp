#include <stack>

using namespace std;

class MinStack {
private:
  stack<int> full_stack;
  stack<int> min_stack;

public:
  MinStack() {}

  void push(int value) {
    // full_stack should push anyway
    // min_stack should push when: stack is empty or stack.top() < value

    full_stack.push(value);
    if (min_stack.empty() || min_stack.top() >= value) {
      min_stack.push(value);
    }
  }

  void pop() {
    // full stack should pop anyway, unless it is empty
    // min_stack should pop when: stack is not empty, and fullstack.top() ==
    // min_stack.top()
    if (!min_stack.empty() && min_stack.top() == full_stack.top()) {
      min_stack.pop();
    }
    if (!full_stack.empty()) {
      full_stack.pop();
    }
  }

  int top() { return full_stack.top(); }

  int getMin() { return min_stack.top(); }
};
