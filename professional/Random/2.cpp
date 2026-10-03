#include <functional>
#include <iostream>
#include <random>
#include <string>

using namespace std;

auto createDiceValueGenerator() {
  random_device seeder;
  ranlux24_base engine{seeder()};
  uniform_int_distribution<int> distribution{1, 6};
  return bind(distribution, engine);
}

int main() {
  auto generator{createDiceValueGenerator()};
  while (true) {
    std::cout << "Want to play?(Press no to reject)\n";
    string str;
    if (!getline(cin, str) || str == "no") {
      break;
    }

    std::cout << generator() << "\n";
    std::cout << generator() << "\n";
  }
}
