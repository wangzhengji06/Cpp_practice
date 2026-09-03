#include <iostream>

using namespace std;

template <typename T> class Box {
public:
  Box(T height, T width, T length)
      : m_height(height), m_width(width), m_length(length) {}

  void setHeight(T height) { m_height = height; }

  void setWidth(T width) { m_width = width; }

  void setLength(T length) { m_length = length; }

  const T &getHeight() const { return m_height; }

  const T &getWidth() const { return m_width; }

  const T &getLength() const { return m_length; }

  T volume() const { return m_height * m_width * m_length; };

private:
  T m_height;
  T m_width;
  T m_length;
};

int main() {
  Box<int> intBox{1, 2, 3};
  Box<double> doubleBox{1.5, 2.0, 3.0};

  cout << intBox.getHeight() << '\n';
  cout << intBox.volume() << '\n';

  cout << doubleBox.getHeight() << '\n';
  cout << doubleBox.volume() << '\n';
}
