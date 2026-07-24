#include <print>

using namespace std;

enum class Color { RED, GREEN, BLUE };

void processColor(Color color) {
  switch (color) {
  case (Color::RED):
    println("This is red!");
    break;
  case (Color::GREEN):
    println("This is green!");
    break;
  case (Color::BLUE):
    println("This is blue!");
    break;
  }
}

int main() { auto nice = static_cast<int>(Color::RED); }
