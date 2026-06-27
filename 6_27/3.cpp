#include <iostream>
enum class Day {
  Monday = 1,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

int main() {
  int input;

  std::cout << "Please input a number from 1 to 7: \n";
  std::cin >> input;
  using enum Day;

  Day day = static_cast<Day>(input);

  switch (day) {
  case Monday:
    std::cout << "Monday\n";
    break;
  case Tuesday:
    std::cout << "Tuesday\n";
    break;
  case Wednesday:
    std::cout << "Wednesday\n";
    break;
  case Thursday:
    std::cout << "Thursday\n";
    break;
  case Friday:
    std::cout << "Friday\n";
    break;
  case Saturday:
    std::cout << "Saturday\n";
    break;
  case Sunday:
    std::cout << "Sunday\n";
    break;
  default:
    std::cout << "You did not input a valid day number\n";
  }
}
