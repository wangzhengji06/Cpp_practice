// Problem: I need to place all the even numbers after the odd numbers

// Initial Thought: I can use two iterators. Right one keeps iterating, left one
// just points to the last even place or right itself. When right hits an odd,
// then replace happesn,
//
// [1 2 5 3 6 5 ]

// Gap: My initial two-pointer approach was correct, but I struggled to reason
// about what happens after swapping. Specifically, I worried that after
// swapping an odd number with an even number and incrementing left, the next
// element at left might already be odd. The gap was that I focused on
// individual elements instead of establishing a loop invariant.

// Use two pointers to partition the array in-place. nright scans the entire
// array. left indicates the next position where an odd number should be placed.

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> trainingPlan(vector<int> &actions) {
    int left{0};
    int right{0};

    while (right < static_cast<int>(actions.size())) {
      // if right hits an odd, swap, left++, right++
      if (actions[right] % 2 != 0) {
        auto temp = actions[left];
        actions[left++] = actions[right];
        actions[right++] = temp;
      } else {
        ++right;
      }
      // if right hits an even, right++, do nothing
    }
    return actions;
  }
};
