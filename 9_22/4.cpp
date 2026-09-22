#include <map>
#include <print>
#include <string>

using namespace std;

int main() {
  map<string, int> my_map;
  my_map.emplace("apple", 100);
  my_map.emplace("banana", 200);
  my_map.emplace("cherry", 300);

  for (auto [a, b] : my_map) {
    println("{}:{}", a, b);
  }
}
