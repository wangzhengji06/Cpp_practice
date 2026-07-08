#include <print>

using namespace std;

struct Base {
  int m_int;
};

struct Derived : Base {};

int main() {
  Derived derived{};
  println("{}", derived.m_int);
}
