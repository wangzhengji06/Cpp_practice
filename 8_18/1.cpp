#include <print>

auto findMax(auto a, auto b) { return a < b ? b : a; }

int main() { std::println("{}", findMax(3, 5)); }
