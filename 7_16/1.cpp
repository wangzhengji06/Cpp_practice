#include <iostream>

using namespace std;

int main() {
  const int a = 7;
  int *p = (int *)&a;
  *p = 8;
  cout << a << "\n";
}
