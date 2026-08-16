#include <string>
#include <vector>

using namespace std;

std::vector<int> buildLps(const string &pattern) {
  vector<int> lps(pattern.size(), 0);

  int len = 0;
  int i = 1;
  while (i < pattern.size()) {
    if (pattern[i] == pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else if (len > 0) {
      len = lps[len - 1];
    } else {
      ++i;
    }
  }
  return lps;
}

int kmpSearch(const string &text, const string &pattern) {
  if (pattern.empty()) {
    return 0;
  }

  auto lps = buildLps(pattern);

  int i = 0;
  int j = 0;
  while (i < text.size()) {
    if (text[i] == pattern[j]) {
      i++;
      j++;

      if (j == pattern.size()) {
        return i - j;
      }
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      ++i;
    }
  }
  return -1;
}
