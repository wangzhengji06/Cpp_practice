// Problem: I understand this question is pretty intuitive.
// In backtrack function, I  iterate over the possible values and select one
// possible value for that character, and go ahead.

// Initial Reasoning: But what state should I  save? 1. What are the previous
// concatenated string by choice 2.  is the character location that I need to
// act now. 3. digitis string itself. What would be the stop condition? when
// this i is out of size

// Investgation: When I was doing the code, I realize that it was indeed a
// simple one. Observation: Nothing Determination:Nothing

// Reflection: I forgot to write the return clause for the backtrack.

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string current{};
    backtrack(current, 0, digits);
    return results;
  }

  void backtrack(string &current, int i, const string &digits) {
    if (i == digits.size()) {
      results.push_back(current);
      return;
    }
    char current_char = digits[i];
    for (char c : mymap[current_char]) {
      current.push_back(c);
      backtrack(current, i + 1, digits);
      current.pop_back();
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
