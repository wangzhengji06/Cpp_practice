#include <algorithm>
#include <iterator>
using namespace std;

template <std::forward_iterator InputIt>
void geneate_fibonacci(InputIt first, InputIt last) {
  int value_0{0};
  int value_1{1};
  int value_2;
  auto fibonacci = [&value_0, &value_1]() {
    auto result = value_0;
    auto next = value_0 + value_1;

    value_0 = value_1;
    value_1 = next;

    return result;
  };
  generate(first, last, fibonacci);
}
