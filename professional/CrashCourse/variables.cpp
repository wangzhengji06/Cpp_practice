#include <print>

using namespace std;

int main() {
  int uninitializedInt;
  int initializedInt{7};
  println("{} is a random value", uninitializedInt);
  println("{} was assigned an initial value", initializedInt);
}
