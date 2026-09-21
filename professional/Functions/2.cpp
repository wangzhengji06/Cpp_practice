#include <functional>
#include <print>

using namespace std;

void func(int num, string_view str) { println("func({}, {})", num, str); }

int main() {
  string myString{"abc"};
  auto f1{bind(func, placeholders::_1, myString)};
  f1(16);

  // Rearrange arguments
  auto f2{bind(func, placeholders::_2, placeholders::_1)};
  f2("Test", 32);

  // Altnative using the lambda function
  auto f1_lambda{[myString](int num) { func(num, myString); }};
  auto f2_lambda{[](string_view str, int num) { func(num, str); }};
}
