#include <algorithm>
#include <deque>
#include <iterator>
#include <print>
#include <vector>

using namespace std;

int main() {
  vector<int> values(20);

  int value = 0;

  ranges::generate(values, [&value] { return ++value; });

  deque<int> evens;
  deque<int> odds;

  ranges::partition_copy(values, back_inserter(evens), front_inserter(odds),
                         [](int value) { return value % 2 == 0; });

  println("values: {:n}", values);
  println("evens:  {:n}", evens);
  println("odds:   {:n}", odds);
}
