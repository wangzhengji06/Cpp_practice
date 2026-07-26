#include <print>

int *findMax(int arr[], int size) {
  auto max = &arr[0];
  for (int i = 1; i < size; ++i) {
    max = arr[i] > *max ? &arr[i] : max;
  }
  return max;
}

int main() {
  int nice[5]{1, 2, 3, 4, 5};
  auto k = findMax(nice, 5);
  std::println("{}", *k);
}
