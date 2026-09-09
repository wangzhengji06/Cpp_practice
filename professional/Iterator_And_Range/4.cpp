#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers;

  for (auto value : ranges::istream_view<int>(cin) |
                        views::take_while([](int v) { return v != -1; })) {
    numbers.push_back(value);
  }

  println("{}", numbers);
}
