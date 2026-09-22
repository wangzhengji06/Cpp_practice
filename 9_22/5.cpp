#include <print>
#include <string>
#include <unordered_map>

using namespace std;

void addTen(unordered_map<string, int> &my_map, const string &key) {
  if (my_map.contains(key)) {
    my_map[key] += 10;
  } else {
    my_map[key] = 10;
  }
}

int main() {
  unordered_map<string, int> my_map;
  my_map.emplace("apple", 100);
  my_map.emplace("banana", 200);
  my_map.emplace("cherry", 300);

  for (auto [a, b] : my_map) {
    println("{}:{}", a, b);
  }

  addTen(my_map, "apple");
}
