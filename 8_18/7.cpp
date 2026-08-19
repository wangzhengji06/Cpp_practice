class Base {
public:
  virtual ~Base() = default;

private:
  int data1;
  int data2;
};

class Derived : public Base {
public:
  virtual ~Derived() = default;

private:
  int data3;
};

int main() {
  Derived derived{};
  Base *b = static_cast<Base *>(&derived);
  Derived *d = dynamic_cast<Derived *>(b);
}
