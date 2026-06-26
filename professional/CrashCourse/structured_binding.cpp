#include <print>

using namespace std;

struct Point {
  double m_x, m_y, m_z;
};

int main() {
  Point point;
  point.m_x = 1.0;
  point.m_y = 2.0;
  point.m_z = 3.0;
  auto [x, y, z]{point};

  println("{}", x);

  double x1;

  println("{}", x1);
}
