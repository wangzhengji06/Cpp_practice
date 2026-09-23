#include <print>
#include <string>
#include <tuple>

using namespace std;

int main() {
  tuple<int, string, double> my_tuple{2, "nice", 3.0};
  println("my_tuple: {}, {}, {}", get<0>(my_tuple), get<1>(my_tuple),
          get<2>(my_tuple));

  auto &[a, b, c] = my_tuple;
  println("my_tuple: {}, {}, {}", a, b, c);
}
