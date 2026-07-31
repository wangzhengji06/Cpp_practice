#include <print>
using namespace std;

class Complex {
public:
  Complex(double real = 0, double imag = 0) : m_real{real}, m_imag{imag} {}
  void display() const { print("{} + {}i", m_real, m_imag); }
  double getReal() const { return m_real; }
  double getImag() const { return m_imag; }

private:
  double m_real = 0;
  double m_imag = 0;
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
  return Complex{lhs.getReal() + rhs.getReal(), lhs.getImag() + rhs.getImag()};
}

int main() {
  Complex a{3, 5};
  Complex b{4, 6};
  Complex c = a + b;
  c.display();
}
