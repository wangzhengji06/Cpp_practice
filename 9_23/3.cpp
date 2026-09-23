#include <print>
#include <set>

using namespace std;

int main() {
  set<int> my_set;
  my_set.insert(1);
  my_set.insert(3);
  my_set.insert(5);
  my_set.insert(7);
  my_set.insert(9);

  for (int x : my_set) {
    println("{}", x);
  }
}
