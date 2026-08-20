#include <exception>
#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException : public exception {
public:
  virtual const char *what() const noexcept override {
    return message_.c_str();
  }

private:
  string message_ = "Cannot divide by zero!";
};

double divide(int a, int b) {
  if (b == 0) {
    throw DivideByZeroException{};
  }
  return static_cast<double>(a) / static_cast<double>(b);
}

int main() {
  try {
    double result = divide(1, 0);
  } catch (const DivideByZeroException &e) {
    cout << "Caught an exception: " << e.what() << endl;
  }
}
