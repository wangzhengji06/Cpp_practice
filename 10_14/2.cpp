

class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 0;
    int right = num / 2 + 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (mid == num / mid && num & mid == 0) {
        return true;
      } else if (mid == num / mid && num % mid != 0) {
        return false;
      } else if (mid < num / mid) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
