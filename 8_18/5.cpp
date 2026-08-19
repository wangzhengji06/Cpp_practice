#include <iostream>

class Base {
public:
  virtual ~Base() { std::cout << "Base desctructor is called"; };
};

class Derived : public Base {
public:
  virtual ~Derived() override { std::cout << "Derived destructor is called"; }
};

int main() {
  Derived d{};
  Base *b = &d;
  Derived *derived = dynamic_cast<Derived *>(b);
}
