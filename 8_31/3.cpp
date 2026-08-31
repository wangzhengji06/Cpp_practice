#include <print>

using namespace std;

void printType(auto &&param) {
  std::println("{}", std::is_lvalue_reference_v<decltype(param)>);
}
