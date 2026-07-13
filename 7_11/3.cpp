#include <print>
namespace Geometry {
const double pi = 3.1415926;
}
namespace Geometry::Shapes {
double calculateArea(double radius) { return pi * radius * radius; }
double calculatePerimeter(double radius) { return 2 * pi * radius; }
} // namespace Geometry::Shapes

int main() {
  using namespace Geometry::Shapes;
  double area{calculateArea(3)};
  double perimeter{calculatePerimeter(3)};
  std::println("area: {:g}, perimeter: {:g}", area, perimeter);
}
