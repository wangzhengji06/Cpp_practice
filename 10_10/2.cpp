#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int result{0};
  int type;
  int amount;
  for (int i = 0; i < n; ++i) {
    cin >> type;
    cin >> amount;
    switch (type) {
    case 1:
      result += amount;
      break;
    case 2:
      result = result < amount ? result : result - amount;
      break;
    case 3:
      result = result % amount == 0 ? result - (result / amount)
                                    : result - 1 - (result / amount);
      break;
    }
  }
  std::cout << result << "\n";
}
