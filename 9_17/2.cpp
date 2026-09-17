#include <iostream>
#include <queue>

int main() {
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  while (!q.empty()) {
    std::cout << q.front() << "\n";
    q.pop();
  }
}
