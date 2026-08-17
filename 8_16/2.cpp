#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
  int result{0};
  unordered_map<char, int> map_table{{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};

  for (int i = 0; i < s.size(); ++i) {
    if (i < s.size() - 1) {
      if (map_table[s[i]] >= map_table[s[i + 1]]) {
        result += map_table[s[i]];
      } else {
        result -= map_table[s[i]];
      }
    } else {
      result += map_table[s[i]];
    }
  }
  return result;
}
