#include <iostream>
#include <print>

using namespace std;

int main() {
  int *ptr = (int *)malloc(sizeof(int) * 100);
  if (ptr == NULL) {
    return 0;
  }
  println("Time to print something(please make sure less than 100 values): ");
  int num;
  int i = 0;
  while (cin >> num) {
    ptr[i] = num;
    ++i;
    if (i == 100) {
      break;
    }
  }
  for (int j = 0; j < i; ++j) {
    cout << ptr[j] << ' ';
  }
  println();

  free(ptr);
  ptr = NULL;
}
