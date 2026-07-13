#include <memory>
#include <print>

using namespace std;

struct Point {
  double m_x;
  double m_y;
  double m_z;

  Point(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}
};

void print_point(const Point &x) {
  println("x={:g}, y={:g}, z={:g}", x.m_x, x.m_y, x.m_z);
}

int main() {
  auto Pointptr{make_unique<Point>(1.0, 2.0, 3.0)};
  print_point(*Pointptr);
}
