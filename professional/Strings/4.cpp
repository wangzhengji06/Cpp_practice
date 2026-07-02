#include <iostream>
#include <print>
#include <vector>

using namespace std;

int main() {
  println("Please enter floating numbers, one line for each floating number.");
  println("Enter 0 to stop.");

  vector<float> numbers;
  float num{};

  do {
    cin >> num;

    if (num != 0) {
      numbers.push_back(num);
    }
  } while (num != 0);

  println("| {:>12} | {:>12} | {:>12} |", "Default", "Fixed", "Scientific");
  for (const auto number : numbers) {
    println("| {:>12} | {:>12.2f} | {:>12e} |", number, number, number);
  }
}
