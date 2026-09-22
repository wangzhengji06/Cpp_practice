#include <print>
#include <queue>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(3);
  q.push(1);
  q.push(4);
  q.push(1);
  q.push(5);
  q.push(9);
  q.push(2);

  while (!q.empty()) {
    int top = q.top();
    println("the top is {}", top);
    q.pop();
  }
}
