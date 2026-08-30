#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    // Reorder into the heap from bottom
    // Maybe something like void reorder(vector<int>& nums)
    // I also need to realize heapify
    // Then I should start the heapSort(vector<int> &nums)
    int len = static_cast<int>(nums.size());
    int size = len;
    for (int i = len / 2 - 1; i >= 0; --i) {
      heapify(nums, i, size);
    }
    for (int i = len - 1; i >= 1; i--) {
      swap(nums, 0, i);
      heapify(nums, 0, i);
    }
    return nums;
  }

  void heapify(vector<int> &array, int i, int size) {
    // check left child and right child, which one is the larger
    int left = i * 2 + 1;
    while (left < size) {
      int right = left + 1;
      int winner = right < size && array[right] > array[left] ? right : left;
      if (array[i] >= array[winner]) {
        break;
      } else {

        swap(array, i, winner);
        i = winner;
        left = i * 2 + 1;
      }
    }
  }

  void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};
