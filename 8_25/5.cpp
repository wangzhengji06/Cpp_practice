#include <print>
#include <string>
#include <utility>

class StringWrapper {
public:
  StringWrapper(std::string str) : message(std::move(str)) {}

  StringWrapper(StringWrapper &&other) noexcept
      : message(std::move(other.message)) {}

  StringWrapper &operator=(StringWrapper &&other) {
    message = std::move(other.message);
    return *this;
  }

  void show() const { print("{}", message); }

private:
  std::string message;
};

int main() {
  StringWrapper a{"Hello World"};

  std::println("移动前:");
  std::print("a = ");
  a.show();

  StringWrapper b{std::move(a)};

  std::println("\n移动构造后:");
  std::print("a = ");
  a.show();
  std::print("b = ");
  b.show();

  StringWrapper c{"Another String"};

  c = std::move(b);

  std::println("\n移动赋值后:");
  std::print("b = ");
  b.show();
  std::print("c = ");
  c.show();
}
