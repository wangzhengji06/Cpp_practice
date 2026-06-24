#include <unordered_map>
#include <vector>

using namespace std;

// Store the value and index into a pair

vector<int> twoSum(vector<int> &nums, int target) {
  std::unordered_map<int, int> valueIndex;
  std::vector<int> result{};
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (valueIndex.find(target - nums[i]) != valueIndex.end()) {
      result.push_back(valueIndex[target - nums[i]]);
      result.push_back(i);
    }
    valueIndex.insert(std::pair<int, int>{nums[i], i});
  }
  return result;
}
