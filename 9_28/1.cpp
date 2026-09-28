#include <random>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    quickSort(0, static_cast<int>(nums.size() - 1), nums);
  }

  void quickSort(int l, int r, vector<int> &nums) {
    if (l >= r) {
      return;
    }
    uniform_int_distribution<int> dist(l, r);
    int x = nums[dist(gen)];
    auto [a, b] = partition(l, r, x, nums);
    quickSort(l, a - 1, nums);
    quickSort(b + 1, r, nums);
  }

  pair<int, int> partition(int l, int r, int target, vector<int> &num) {
    int a = l;
    int b = r;
    int i = l;
    while (i <= b) {
      if (num[i] == target) {
        ++i;
      } else if (num[i] < target) {
        swap(i++, a++, num);
      } else {
        swap(i, b--, num);
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
