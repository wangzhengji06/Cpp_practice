#include <iostream>

union Data {
  int m_int;
  float m_float;
  char m_char;
};

int main() {
  Data data;
  char type;
  std::cout << "Please tell me what type do you want(i/f/c): \n";
  std::cin >> type;
  std::cout << "Please input the data: \n";
  switch (type) {
  case ('i'): {
    std::cin >> data.m_int;
    std::cout << data.m_int << '\n';
    break;
  }
  case ('f'): {
    std::cin >> data.m_float;
    std::cout << data.m_float << '\n';
    break;
  }
  case ('c'): {
    std::cin >> data.m_char;
    std::cout << data.m_char << '\n';
    break;
  }
  default: {
    std::cout << "only support the 3 types.\n";
  }
  }
}
