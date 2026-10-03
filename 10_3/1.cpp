#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }

    string path;
    backtrack(path, 0, digits);

    return results;
  }

  void backtrack(string &path, int i, const string &digits) {
    if (i == digits.size()) {
      results.push_back(path);
      return;
    }

    for (char c : mymap[digits[i]]) {
      path.push_back(c);

      backtrack(path, i + 1, digits);

      path.pop_back();
    }
  }

private:
  vector<string> results;

  unordered_map<char, vector<char>> mymap{
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
};
