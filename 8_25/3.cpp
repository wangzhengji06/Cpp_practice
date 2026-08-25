class MyClass {
public:
  MyClass(const MyClass &other) : size(other.size), list(new int[other.size]) {
    for (int i = 0; i < other.size; ++i) {
      list[i] = other.list[i];
    }
  }

  ~MyClass() { delete[] list; }

private:
  int size;
  int *list;
};
