#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  unordered_set<int> love_letters;
  char j;
  for (int i = 0; i < m; ++i) {
    cin >> j;
    love_letters.insert(j);
  }
  string s(n, ' ');
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int left = -1;
  int right = 0;

  auto replace = [&](int left, int right) {
    for (int i = left + 1; i < right; ++i) {
      if (i - left <= right - i) {
        s[i] = s[left];
      } else {
        s[i] = s[right];
      }
    }
  };

  while (left != n) {
    while (right != n && !love_letters.contains(s[right])) {
      ++right;
    }
    if (left == -1) {
      for (int i = 0; i < right; ++i) {
        s[i] = s[right];
      }
    } else if (right == n) {
      for (int i = left; i < n; ++i) {
        s[i] = s[left];
      }
    } else {
      replace(left, right);
    }
    left = right;
    if (right < n) {
      ++right;
    }
  }

  cout << s << '\n';
}
