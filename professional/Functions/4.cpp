#include <print>
#include <vector>

using namespace std;

int main() {
  vector values{1, 2, 3, 2, 1, 2, 4, 5};
  println("{:n}", values);
  erase(values, 2); // Removes all values equal to 2.
  println("{:n}", values);

  erase_if(values, [](int n) { return n % 2 != 0; });
}
