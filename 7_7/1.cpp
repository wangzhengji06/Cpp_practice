#include <print>

class StudentClass {
  int m_number;

public:
  int getNumber() { return m_number; }
};

struct StudentStruct {
  int m_number;
  int getNumber() { return m_number; }
};

int main() {
  StudentClass student1;
  StudentStruct student2;

  std::println("{}", student1.getNumber());

  std::println("{}", student2.m_number);
}
