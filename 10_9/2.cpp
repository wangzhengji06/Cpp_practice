#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, a, b, c;
vector<int> s;
vector<vector<vector<int>>> dp;

int dfs(int l, int r, int k) {
  if (l > r) {
    return 0;
  }

  int &res = dp[l][r][k];

  if (res != -1) {
    return res;
  }

  int score[3] = {a, b, c};
  res = score[k] + dfs(l + 1, r, 0);

  if (k < 2) {
    for (int j = l + 1; j <= r; ++j) {
      if (s[j] == s[l]) {
        res = max(res, dfs(l + 1, j - 1, 0) + dfs(j, r, k + 1));
      }
    }
  }

  return res;
}

int main() {
  cin >> n >> a >> b >> c;

  s.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  dp.assign(n, vector<vector<int>>(n, vector<int>(3, -1)));
  cout << dfs(0, n - 1, 0) << '\n';
}
