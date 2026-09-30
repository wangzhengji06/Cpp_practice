#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> my_stack;
    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        my_stack.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        switch (c) {
        case ')':
          if (my_stack.size() == 0 || my_stack.top() != '(') {
            return false;
          }
          break;
        case '}':
          if (my_stack.size() == 0 || my_stack.top() != '{') {
            return false;
          }
          break;
        case ']':
          if (my_stack.size() == 0 || my_stack.top() != '[') {
            return false;
          }
          break;
        }
        my_stack.pop();
      } else {
        return false;
      }
    }
    return my_stack.size() == 0;
  }
};
