#include <iostream>
#include <queue>

int main() {
  std::queue<int> q;

  q.push(1);
  std::cout << "empty: " << q.empty() << ", size: " << q.size() << '\n';

  q.push(2);
  std::cout << "empty: " << q.empty() << ", size: " << q.size() << '\n';

  q.pop();
  std::cout << "empty: " << q.empty() << ", size: " << q.size() << '\n';

  q.pop();
  std::cout << "empty: " << q.empty() << ", size: " << q.size() << '\n';
}
