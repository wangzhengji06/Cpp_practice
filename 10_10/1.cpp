#include <iostream>
#include <vector>
using namespace std;

int main() {
  int result = 0;
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  if (n < k) {
    return 1;
  }
  vector<int> a_array(n);
  vector<int> b_array(n);
  for (int i = 0; i < n; ++i) {
    cin >> a_array[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b_array[i];
  }

  int invalid = 0;

  for (int i = 0; i < k; ++i) {
    if (a_array[i] < a || b_array[i] < b) {
      ++invalid;
    }
  }

  if (invalid == 0) {
    ++result;
  }
  int left = 0;
  int right = k;

  for (int right = k; right < n; ++right) {
    int left = right - k;

    if (a_array[left] < a || b_array[left] < b) {
      --invalid;
    }

    if (a_array[right] < a || b_array[right] < b) {
      ++invalid;
    }

    if (invalid == 0) {
      ++result;
    }
  }
  cout << result << "\n";
}
