#include <exception>
#include <expected>
#include <print>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class DataError : public exception {
public:
  explicit DataError(string message) : m_message{std::move(message)} {}
  const string &getMessage() const { return m_message; }

private:
  string m_message;
};

expected<vector<int>, DataError> getData(bool fail) {
  if (fail) {
    return unexpected{DataError{"Failed to get data"}};
  }

  return vector{1, 2, 3, 4};
}

int main() {
  auto result = getData(false);

  if (result) {
    for (int value : *result) {
      print("{} ", value);
    }
    println();
  } else {
    println("Error: {}", result.error().getMessage());
  }
}
