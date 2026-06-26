#include <iostream>

using namespace std;

int main() {
  int *ptr = (int *)calloc(10, sizeof(int));
  if (ptr == NULL) {
    return 0;
  }
  int *temp = (int *)realloc(ptr, sizeof(int) * 20);
  if (temp == NULL) {
    free(ptr);
    ptr = NULL;
    return 0;
  } else {
    ptr = temp;
  }
  for (int i = 10; i < 20; ++i) {
    ptr[i] = 1;
  }
  for (int i = 0; i < 20; ++i) {
    cout << ptr[i] << ' ';
  }
  cout << '\n';
  free(ptr);
  ptr = NULL;
}
