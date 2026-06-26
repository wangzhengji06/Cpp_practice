struct Employee {
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary{75'000};
};

int main() {
  Employee employee_a{'J', 'D', 42, 80'000};
  Employee employee_b{.firstInitial = 'J', .lastInitial = 'D'};
}
