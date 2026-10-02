#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    help.resize(nums.size());
    mergeSort(0, static_cast<int>(nums.size()) - 1, nums);
    return nums;
  }

  void mergeSort(int l, int r, vector<int> &nums) {
    if (l >= r) {
      return;
    }
    int m = (l + r) / 2;
    mergeSort(l, m, nums);
    mergeSort(m + 1, r, nums);
    merge(l, m, r, nums);
  }

  void merge(int l, int m, int r, vector<int> &nums) {
    int i = l;
    int a = l;
    int b = m + 1;

    while (a <= m && b <= r) {
      help[i++] = (nums[a] <= nums[b] ? nums[a++] : nums[b++]);
    }
    while (a <= m) {
      help[i++] = nums[a++];
    }
    while (b <= r) {
      help[i++] = nums[b++];
    }

    for (int j = l; j <= r; ++j) {
      nums[j] = help[j];
    }
  }

private:
  vector<int> help;
};
