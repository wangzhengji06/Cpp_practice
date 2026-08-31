#include <print>
#include <string>
#include <utility>

using namespace std;

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

  std::println("Before moving:");
  std::print("a = ");
  a.show();

  StringWrapper b{std::move(a)};

  std::println("\nAfter moving:");
  std::print("a = ");
  a.show();
  std::print("b = ");
  b.show();

  StringWrapper c{"Another String"};

  c = std::move(b);

  std::println("\nAfter assignment:");
  std::print("b = ");
  b.show();
  std::print("c = ");
  c.show();
}
