#include <exception>
#include <memory>
#include <print>
#include <stdexcept>

struct Resource {
  Resource() { std::println("Got created!"); };
  ~Resource() { std::println("Got deleted!"); };
};

void throw_error() {
  auto my_ptr{std::make_shared<Resource>()};
  throw std::runtime_error("What is going on here?");
}

int main() {
  try {
    throw_error();
  } catch (const std::exception &e) {
    std::println("Caught exception: {}", e.what());
  }
}
