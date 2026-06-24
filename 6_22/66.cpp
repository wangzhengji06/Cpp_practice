
#include <vector>

using namespace std;

// From right to left, ++elem for the most right if not 9, change to  0 and add
// 1 to left if 9 and left exists, else add 1 to left

vector<int> add_one(vector<int> &target) {
  for (int i = target.size() - 1; i > -1; --i) {
    if (target[i] != 9) {
      ++target[i];
      return target;
    } else {
      target[i] = 0;
      if (i == 0) {
        vector<int> new_target(target.size() + 1);
        new_target[0] = 1;
        for (int i = 0; i < target.size(); ++i) {
          new_target[i + 1] = target[i];
        }
        return new_target;
      } else {
        continue;
      }
    }
  }
  return target;
}
