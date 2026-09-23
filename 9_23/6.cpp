#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

tuple<int, int, double> check(const vector<int> &nums) {
  double sum = 0.0;
  for (int num : nums) {
    sum += num;
  }

  return tuple{*max(nums.begin(), nums.end()), *min(nums.begin(), nums.end()),
               sum / nums.size()};
}
