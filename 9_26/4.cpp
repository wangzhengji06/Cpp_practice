#include <algorithm>
#include <print>
#include <vector>

int main() {
  std::vector<int> my_vec{1, 2, 3, 4, 5};
  std::ranges::for_each(my_vec, [](int &p) { p = p * p; });
  std::println("{:n}", my_vec);
}
