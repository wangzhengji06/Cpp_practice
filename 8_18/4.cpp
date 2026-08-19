#include <initializer_list>
#include <stdexcept>
class Box {
public:
  Box(int width, int height) : m_width(width), m_height(height) {};
  Box(std::initializer_list<int> values) {
    if (values.size() != 2) {
      throw std::invalid_argument{"initializer_list should contain 2 elements"};
    } else {
      m_width = *values.begin();
      m_height = *(values.begin() + 1);
    }
  }

private:
  int m_width;
  int m_height;
};
