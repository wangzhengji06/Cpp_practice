#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &arr, int target) {
    if (arr.empty()) {
      return -1;
    }

    if (arr[0] == target) {
      return 0;
    }

    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == target) {
        if (mid == 0 || arr[mid - 1] != target) {
          return mid;
        }

        right = mid - 1;
        continue;
      }

      if (arr[left] < arr[mid]) {

        if (arr[left] <= target && target < arr[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (arr[left] > arr[mid]) {
        if (arr[mid] < target && target <= arr[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      else {
        ++left;
      }
    }

    return -1;
  }
};
