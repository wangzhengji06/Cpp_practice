#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
};

int main() {
  Point *point_array{new Point[5]{Point{0, 1}, Point{0, 2}, Point{1, 0},
                                  Point{2, 0}, Point{1, 1}}};

  for (int i = 0; i < 5; ++i) {
    cout << point_array[i].x << " " << point_array[i].y << endl;
  }

  delete[] point_array;
}
