#include <print>

class IsLargerThan {
public:
  explicit IsLargerThan(int value) : m_value{value} {}
  bool operator()(int value1, int value2) const {
    return value1 > m_value && value2 > m_value;
  }

private:
  int m_value;
};

int main() {
  int value;
  auto isLargerThan{[value](int value1, int value2) {
    return value1 > value && value2 > value;
  }};
  std::println("{}", isLargerThan(1, 2));
}
