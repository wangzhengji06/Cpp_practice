#include "person.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  Person person{"John", "Doe"};

  print("Directly to output stream: ");
  person.output(cout);

  ostringstream oss;
  person.output(oss);
  print("To string stream: ");
  cout << oss.str() << endl;

  ofstream outFile{"person.txt"};
  person.output(outFile);
}
