#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  unordered_map<int, int> voters;
  int base{};

  int party;
  for (int i = 0; i < n; ++i) {
    cin >> party;
    if (party == x) {
      ++base;
      continue;
    }

    ++voters[party];
  }
  int result = base;
  for (auto [party, number] : voters) {
    if (base + number > result) {
      result = base + number;
    }
  }
  cout << result << "\n";
}
