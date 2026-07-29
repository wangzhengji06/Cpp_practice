using FuncPtr = int (*)(int);

int modifyArray(int value) { return value * value; }

void applyArray(int *array, int size, FuncPtr fcp) {
  for (int i = 0; i < size; ++i) {
    array[i] = fcp(array[i]);
  }
}
