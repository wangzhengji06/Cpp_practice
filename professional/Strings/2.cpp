#include <print>
#include <string>

using namespace std;

string replaceString(string haystack, const string &needle,
                     const string &replacement) {
  if (needle.empty()) {
    return haystack;
  }
  while (haystack.contains(needle)) {
    auto pos{haystack.find(needle)};
    haystack.replace(pos, needle.size(), replacement);
  }
  return haystack;
}

int main() {
  string target{"Nice move Captain, You are a Nice Person"};
  println("{}", replaceString(target, string{"Nice"}, string{"Bad"}));
}
