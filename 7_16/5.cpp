#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(string s) {
  stack<char> collector;
  for (char c : s) {
    if (!collector.empty() && collector.top() == c) {
      collector.pop();
    } else {
      collector.push(c);
    }
  }
  string result;
  while (!collector.empty()) {
    result.push_back(collector.top());
    collector.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}
