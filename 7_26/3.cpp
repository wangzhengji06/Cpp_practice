#include <stack>
#include <vector>

using namespace std;

int trap(vector<int> &height) {
  // Maintain a monotonically non-increasing stack.
  // If the current height is greater than the stack top,
  // pop the bottom and calculate trapped water using
  // the new stack top as the left boundary.
  int result = 0;
  stack<int> container;

  for (int i = 0; i < height.size(); ++i) {
    while (!container.empty() && height[i] > height[container.top()]) {
      int bottomIndex = container.top();
      container.pop();

      if (container.empty()) {
        break;
      }

      int left = container.top();
      int waterHeight = min(height[left], height[i]) - height[bottomIndex];

      int width = i - left - 1;
      result += waterHeight * width;
    }
    container.push(i);
  }
  return result;
}
