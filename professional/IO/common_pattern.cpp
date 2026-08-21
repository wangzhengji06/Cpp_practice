#include <iostream>
#include <print>

using namespace std;

int main() {
  println("Enter numbers on seperate lines to add.");
  println("Use Control+D followed by Enter to finish (Control+Z in windows)");
  int sum{0};

  if (!cin.good()) {
    println(cerr, "Standard input is in a bad state!");
    return 1;
  }
  while (!cin.bad()) {
    int number;
    cin >> number;

    if (cin.good()) {
      sum += number;
    } else if (cin.eof()) {
      break;
    } else if (cin.fail()) {
      cin.clear();
      string badToken;
      cin >> badToken; // Consume the bad input
      println(cerr, "WARNING: Bad input encountered: {}", badToken);
    }
  }
  println("The sum is {}.", sum);
}
