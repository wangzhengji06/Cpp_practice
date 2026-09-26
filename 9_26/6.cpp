#include <print>

#include <memory>
int *make_array(int n) {
  auto array = std::make_unique<int[]>(n);
  for (int i = 0; i < n; ++i) {
    array[i] = 1 + i;
  }
  return array.release();
}

int main() {
  int *arr = make_array(5);

  for (int i = 0; i < 5; ++i) {
    std::println("{}", arr[i]);
  }

  delete[] arr;
}
