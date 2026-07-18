#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
  stack<char> stk;
  char choice;
  for (char c : s) {
    if (c == '(' or c == '{' or c == '[') {
      stk.push(c);
    } else {
      if (stk.empty()) {
        return false;
      }
      if (c == ')') {
        choice = '(';
      } else if (c == '}') {
        choice = '{';
      } else {
        choice = '[';
      }
      if (stk.top() == choice) {
        stk.pop();
      } else {
        return false;
      }
    }
  }
  return stk.empty();
}
