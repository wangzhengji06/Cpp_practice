#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
template <typename T> class AssociativeArray {
public:
  const T &operator[](const string &key) const {
    for (const auto &[a, b] : data) {
      if (a == key) {
        return b;
      }
    }
    throw out_of_range{"Key not found!"};
  }

  T &operator[](const string &key) {
    for (auto &[a, b] : data) {
      if (a == key) {
        return b;
      }
    }
    data.emplace_back(key, T{});
    return data.back().second;
  }

private:
  vector<pair<string, T>> data;
};

int main() {
  AssociativeArray<int> arr;

  arr["one"] = 1;
  arr["two"] = 2;

  cout << arr["one"] << '\n';
}
