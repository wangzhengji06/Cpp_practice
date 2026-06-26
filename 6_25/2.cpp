#include <iostream>

using namespace std;

void stackPrintArray() {
  cout << "Go print something: \n";

  int num;
  int array[5];

  for (int i = 0; i < 5; ++i) {
    cin >> num;
    array[i] = num;
  }

  for (const int &i : array) {
    cout << i << ' ';
  }

  cout << '\n';
}

void heapPrintArray() {
  cout << "Go print something: \n";

  int num;
  int *array = new int[5];

  for (int i = 0; i < 5; ++i) {
    cin >> num;
    array[i] = num;
  }

  for (int i = 0; i < 5; ++i) {
    cout << array[i] << ' ';
  }

  cout << '\n';

  delete[] array;
}

int main() {
  stackPrintArray();
  heapPrintArray();

  return 0;
}
