#include <ios>
#include <iostream>
#include <print>

using namespace std;

void getReservationDate() {
  print("Name and number of guests: ");
  string guestName;
  int partySize{0};

  char ch;
  cin >> noskipws;
  while (cin >> ch) {
    if (isdigit(ch)) {
      cin.unget();
      if (cin.fail()) {
        println(cerr, "unget() failed.");
      }
      break;
    }
    guestName += ch;
  }
  if (cin) {
    cin >> partySize;
  }
  if (!cin) {
    println(cerr, "Error getting party size.");
    return;
  }

  println("Thank you '{}', party of {}.", guestName, partySize);
  if (partySize > 10) {
    println("An extra gratuity will apply.");
  }
}
