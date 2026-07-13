#include <print>
#include <vector>

using namespace std;

int main() {
  const size_t numberOfElements{10};
  vector<int> values; //// Use a vector, instead of C-style arrays.

  // Add values.
  for (int index{0}; index < numberOfElements; ++index) {
    values.push_back(index);
  }

  // Set last value to 99.
  values.back() = 99;

  // Print all values.
  println("{:n}", values);
}
