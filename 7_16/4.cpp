#include <print>

using namespace std;

class MyClass {
public:
  void change_int() const { m_int++; }
  int getInt() const { return m_int; }
  double getDouble() const { return m_double; }

private:
  mutable int m_int{0};
  double m_double{0};
};

int main() {
  MyClass myclass;
  myclass.change_int();
  println("m_int: {}, m_double: {}", myclass.getInt(), myclass.getDouble());
}
