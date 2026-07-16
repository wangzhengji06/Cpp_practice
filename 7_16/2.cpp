#include <print>

int main() {
  const int *int_ptr{new int{5}};
  *int_ptr = 4;

  int *const my_ptr{new int{6}};
  int *new_ptr{new int{6}};
  my_ptr = new_ptr;
}
