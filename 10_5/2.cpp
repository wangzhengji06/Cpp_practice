#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    stack<int> my_stack;
    int low = 0;
    int high = 0;
    for (char c : s) {
      if (c == '(') {
        ++low;
        ++high;
      } else if (c == ')') {
        low = max(0, --low);
        --high;
      } else {
        low = max(0, --low);
        ++high;
      }

      if (high < 0) {
        return false;
      }
    }
    return low == 0;
  }
};
