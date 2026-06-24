#include<print>

int main() {
  int i {11};
  std::strong_ordering result {i <=> 0};

  if (is_lt(result)) {
    std::println("less");
  }
  if (is_gt(result)) {
    std::println("greater");
  }
  if (is_eq(result)) {
    std::println("equal");
  }
  


}
