#include <array>
#include <optional>
#include <print>
#include <utility>
#include <vector>

using namespace std;
optional<int> getData(bool giveIt) {
  if (giveIt)
    return 42;
  return nullopt;
}

int main() {
  vector<int> myVector{11, 22};

  pair<double, int> myPair{1.23, 5};
  myVector.push_back(33);
  myVector.push_back(44);

  array<int, 3> arr{9, 8, 7};
  println("Array size = {}", arr.size());
  println("2nd element = {}", arr[1]);
  println("{} {} ", myPair.first, myPair.second);

  optional<int> data1{getData(true)};
  optional<int> data2{getData(false)};

  println("data1.has_value = {}", data1.has_value());
  if (!data2) {
    println("data2 has no value");
  }

  println("data1.value={}", data1.value());
  println("data1.value={}", *data1);

  println("data2.value={}", data2.value_or(0));
  
  
}
