#include <chrono>
#include <print>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main() {
  minutes d1{42};
  duration<double, ratio<60>> d2{1.5};

  duration<int> d4{duration_cast<duration<int>>(d1 + d2)};
  println("the exact duration would be: {}", d4);
}
