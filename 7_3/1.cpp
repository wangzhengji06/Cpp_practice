#include <cstring>
#include <print>

using namespace std;

int main() {
  int src[]{1, 2, 3, 4, 5};
  int dest[5]{};

  memcpy(dest, src, sizeof(int) * 5);

  println("{}", dest);
}
