// Problem: I need to design an algorithm to calculate the smallest K
// numbers.  How do I avoid sorting the whole list?

// Initial Thought: I create a priority heap of size k, and I keep iterating and
// pushing to priority heap. I only compare with the biggest one inside heap, if
// smaller, then pop that guy and append it. IT will be O(n)

// Investigation: I implemented the max heap method. It is an acceptable method,
// only edge case is k == 0.

// Observation: Nothing

// Determincation: Nothing

// Reflection: Nothing

#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallestK(vector<int> &arr, int k) {
    vector<int> result;
    if (k == 0) {
      return result;
    }
    int target = k - 1;
    quickSelect(0, static_cast<int>(arr.size()) - 1, arr, target);
    result = vector<int>(arr.begin(), arr.begin() + k);
    return result;
  }

  void quickSelect(int l, int r, vector<int> &nums, int target) {
    if (l >= r) {
      return;
    }
    uniform_int_distribution<int> dist(l, r);
    int x = nums[dist(gen)];
    auto [a, b] = partition(l, r, x, nums);
    if (target < a) { // here it means target less than
      quickSelect(l, a - 1, nums, target);
    } else if (target > b) {
      quickSelect(b + 1, r, nums, target);
    } else {
      return;
    }
  }

  // Rememebr < a are values smaller than target
  // >= a < i is the values eauql to target
  // <= i <=b are values that are not examined
  // > b are values larger than target
  pair<int, int> partition(int l, int r, int target, vector<int> &nums) {
    int a = l;
    int b = r;
    int i = l;
    while (i <= b) {
      if (nums[i] == target) {
        ++i;
      } else if (nums[i] < target) {
        swap(i++, a++, nums);
      } else {
        swap(i, b--, nums);
      }
    }
    return {a, b};
  }

  void swap(int i, int j, vector<int> &num) {
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
  }

private:
  mt19937 gen{random_device{}()};
};
