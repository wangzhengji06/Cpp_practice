#include <print>
#include <ranges>
#include <string>

using namespace std;

void printRange(string_view msg, auto &&range) {
  println("{}{:n}", msg, range);
}

int main() {
  auto result{
      views::iota(10) |
      views::take_while([](const auto &v) { return v < 101; }) |
      views::transform([](const auto &value) { return value * value; }) |
      views::filter([](const auto &value) { return value % 5 != 0; }) |
      views::transform([](const auto &v) { return to_string(v); })};
  printRange("Overall Result: ", result);
}
