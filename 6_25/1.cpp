#include <iostream>
#include <print>

using namespace std;

int main() {
  int *array = new int[5];
  println("Please enter 5 integers:");
  int num;
  for (int i = 0; i < 5; ++i) {
    cin >> num;
    array[i] = num;
  }
  for (int i = 0; i < 5; ++i) {
    print("{} ", array[i]);
  }
  print("\n");
  delete[] array;
}
