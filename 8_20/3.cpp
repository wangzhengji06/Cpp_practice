#include <iostream>
#include <stdexcept>

using namespace std;

double divide(int a, int b) {
  if (b == 0) {
    throw runtime_error("Division By zero is not allowed");
  }
  return static_cast<double>(a) / static_cast<double>(b);
}

void C() { divide(1, 0); }

void B() { C(); }

void A() {
  try {
    B();
  } catch (const exception &e) {
    cout << "Caught an exception: " << e.what() << endl;
  }
};

int main() {
  A();

  cout << "Life goes on" << endl;
  return 0;
}
