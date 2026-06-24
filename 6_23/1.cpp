#include <print>
#include <stdexcept>

void returnLargest(int *targetArr, int size, int &maxValue) {
  if (size <= 0) {
    throw std::runtime_error("Cannot deal with array with no length");
  }
  maxValue = targetArr[0];
  for (int i = 1; i < size; ++i) {
    if (targetArr[i] > maxValue)
      maxValue = targetArr[i];
  }
  std::println("The largest value is {}.", maxValue);
}
