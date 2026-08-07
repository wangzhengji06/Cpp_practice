#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  unordered_set<char> window;
  size_t max = 0;
  size_t left = 0;
  for (char c : s) {
    // does the window contains c? if no add, and check whether it is largert
    // than max and can replace it.
    // if it is, keep erase the left element, left++, until it hits the c
    // then choose your left to be left++, and continue
    if (!window.contains(c)) {
      window.insert(c);
      max = max > window.size() ? max : window.size();
    } else {
      while (s[left] != c) {
        window.erase(s[left]);
        left++;
      }
      left++;
    }
  }
  return max;
}
