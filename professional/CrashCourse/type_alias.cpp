

using IntPtr = int *; // the same as typedef int* IntPtr;

int main() {
  int *p1;
  IntPtr p2;

  p1 = p2;
  p2 = p1;
}
