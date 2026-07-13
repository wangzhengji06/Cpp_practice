#include <print>
namespace {
static int counter;
void incrementCounter() { counter++; }

} // namespace

int main() {
  for (int i = 0; i < 3; ++i) {
    incrementCounter();
  }
  std::println("{}", counter);
}
