#include <string>

using namespace std;

string removeKdigits(string num, int k) {
  string stack;

  for (char c : num) {
    while (!stack.empty() && k > 0 && stack.back() > c) {
      stack.pop_back();
      k--;
    }
    stack.push_back(c);
  }

  while (k > 0 && !stack.empty()) {
    stack.pop_back();
    k--;
  }

  int pos = 0;
  while (pos < stack.size() && stack[pos] == '0') {
    pos++;
  }

  string result = stack.substr(pos);
  return result.empty() ? "0" : result;
}
