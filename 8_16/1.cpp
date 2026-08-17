#include <string>
#include <utility>
#include <vector>

using namespace std;
string intToRoman(int num) {
  string result{""};
  vector<pair<int, string>> map_table{
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

  for (auto [x, y] : map_table) {
    for (int i = 0; i < num / x; ++i) {
      result += y;
    }
    num %= x;
  }
  return result;
}
