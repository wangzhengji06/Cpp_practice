#include <exception>
#include <iostream>
#include <print>
#include <string>
#include <utility>
#include <variant>
#include <vector>
using namespace std;

class DataError : public exception {
public:
  explicit DataError(string message) : m_message{std::move(message)} {}
  const string &getMessage() const { return m_message; }

private:
  string m_message;
};

variant<vector<int>, DataError> getData(bool fail) {
  if (!fail) {
    return vector{1, 2, 3, 4};
  } else {
    return DataError{"numnumnum"};
  }
}

int main() {
  auto result = getData(false);

  if (holds_alternative<vector<int>>(result)) {
    const auto &data = get<vector<int>>(result);

    for (int value : data) {
      print("{} ", value);
    }
    println();
  } else {
    const auto &error = get<DataError>(result);
    println("Error: {}", error.getMessage());
  }
}
