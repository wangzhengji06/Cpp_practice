#include <print>

using namespace std;

class ArrayWrapper {
public:
  ArrayWrapper() { array = new int[5]{1, 2, 3, 4, 5}; }
  ~ArrayWrapper() { delete[] array; }

private:
  int *array;
};

int main() {
  {
    ArrayWrapper wrapper{};
  }

  println("Object is destroyed");
}
