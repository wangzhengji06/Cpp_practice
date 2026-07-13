#include <cstddef>

void use_int(int nice) {}

void use_int_pointer(int *nice_ptr) {}

int main() {
  use_int(0);
  use_int(NULL);    // clang [-Wnull-conversion]: Implicit conversion of NULL
                    // constant to 'int' (fix available)
  use_int(nullptr); // clang [ovl_no_viable_function_in_call]: No matching
                    // function for call to 'use_int'
  use_int_pointer(0);
  use_int_pointer(NULL);
  use_int_pointer(nullptr);
}
