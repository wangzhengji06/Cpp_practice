#include <unordered_set>
#include <vector>

using namespace std;
bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> set;
  for (int &num : nums) {
    if (set.contains(num)) {
      return true;
    } else {
      set.insert(num);
    }
  }

  return false;
}
