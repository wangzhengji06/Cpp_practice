#include <utility>

class MyClass {
public:
  MyClass(const MyClass &other) : size(other.size), list(new int[other.size]) {
    for (int i = 0; i < other.size; ++i) {
      list[i] = other.list[i];
    }
  }

  MyClass(MyClass &&other) noexcept
      : size(std::exchange(other.size, 0)),
        list(std::exchange(other.list, nullptr)) {}

  void swap(MyClass &obj2) noexcept {
    std::swap(size, obj2.size);
    std::swap(list, obj2.list);
  }

  MyClass &operator=(const MyClass &other) {
    MyClass temp{other};
    swap(temp);
    return *this;
  }

  MyClass &operator=(MyClass &&other) {
    MyClass temp{std::move(other)};
    swap(temp);
    return *this;
  }

  ~MyClass() { delete[] list; }

private:
  int size;
  int *list;
};
