#include <algorithm>
#include <ranges>
#include <string>

using namespace std;

string trim(string str) {
  auto first = ranges::find_if_not(
      str, [](char c) { return isspace(static_cast<unsigned char>(c)); });

  auto last = ranges::find_if_not(str | views::reverse, [](char c) {
                return isspace(static_cast<unsigned char>(c));
              }).base();

  if (first >= last) {
    return "";
  }

  return string(first, last);
}
