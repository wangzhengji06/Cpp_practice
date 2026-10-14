#include <print>

using namespace std;

constexpr int fibonacci(int n) {
  int a = 0;
  int b = 1;

  for (int i = 0; i < n; ++i) {
    int temp = a;
    a = b;
    b = temp + a;
  }

  return a;
}
int main() {}
