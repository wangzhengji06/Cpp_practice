#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> L(m);
  vector<int> R(m);
  vector<long long> H(m);

  for (int i = 0; i < m; ++i) {
    cin >> L[i] >> R[i] >> H[i];
    --L[i];
    --R[i];
  }

  auto check = [&](int k) {
    vector<long long> diff(n + 1, 0);
    for (int i = 0; i < k; ++i) {
      diff[L[i]] += H[i];
      diff[R[i] + 1] -= H[i];
    }
    for (int i = 1; i < n + 1; ++i) {
      diff[i] += diff[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      if (diff[i] >= a[i]) {
        return true;
      }
    }
    return false;
  };

  int l = 0;
  int r = m;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << l << "\n";
}
// 64 位输出请用 printf("%lld")
