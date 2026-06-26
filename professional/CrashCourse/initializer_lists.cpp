#include <initializer_list>

using namespace std;


int sum(initializer_list<int> values) {
  int total{0};
  for (int value : values) {
    total += value;
  }
  return total;
}

int main() {
  int a { sum({1, 2, 3, 4, 5})};
}
