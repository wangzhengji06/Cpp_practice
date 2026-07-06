#include <cstring>
#include <print>

using namespace std;

int main() {
  int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  memset(arr, 0, sizeof(arr));

  println("{}", arr);
}
