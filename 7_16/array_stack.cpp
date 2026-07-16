#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> class ArrayStack {
private:
  T *data;
  int capacity;
  int topIndex;

public:
  ArrayStack(int cap = 10) : capacity(cap), topIndex(-1) {
    data = new T[capacity];
  }

  ~ArrayStack() { delete[] data; }

  void push(const T &value) {
    if (isFull()) {
      resize(capacity * 2);
    }
    data[++topIndex] = value;
  }

  T pop() {
    if (isEmpty()) {
      throw runtime_error("Empty Stack!");
    }
    return data[--topIndex];
  }

  T top() const { return data[topIndex]; }

  bool isEmpty() const { return topIndex == -1; }

  bool isFull() const { return topIndex == capacity - 1; }

  int size() const { return topIndex + 1; }

  void print() const {
    cout << "Stack (top -> bottom): ";
    for (int i = topIndex; i >= 0; i--) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

private:
  void resize(int newCapacity) {
    T *newData = new T[newCapacity];
    for (int i = 0; i <= topIndex; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }
};
