#include <print>
#include <vector>

void push_wrapper(std::vector<int> &numbers, int i) {
  numbers.push_back(i);
  std::println("size:{}, capacity:{}", numbers.size(), numbers.capacity());
}

int main() {
  std::vector<int> numbers;
  for (int i = 0; i < 5; ++i) {
    push_wrapper(numbers, i);
  }

  std::println("first is: {}, last is: {}", numbers[0],
               numbers[numbers.size() - 1]);
}
