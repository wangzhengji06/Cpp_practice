#include <queue>
using namespace std;

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    container.push(x);
    int n = container.size();
    for (int i = 0; i < n - 1; ++i) {
      int front = container.front();
      container.pop();
      container.push(front);
    }
  }

  int pop() {
    int front = container.front();
    container.pop();
    return front;
  }

  int top() { return container.front(); }

  bool empty() { return container.size() == 0; }

private:
  queue<int> container;
};
