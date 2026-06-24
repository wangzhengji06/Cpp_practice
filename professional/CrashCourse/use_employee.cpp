import employee;

#include <print>

using namespace std;

int main() {
  // Create and populate an employee.
  Employee anEmployee;
  anEmployee.firstInitial = 'J';
  anEmployee.lastInitial = 'D';
  anEmployee.employeeNumber = 42;
  anEmployee.salary = 80000;
  // Output the values of an employee.
  std::println("Employee: {}{}", anEmployee.firstInitial,
               anEmployee.lastInitial);
  std::println("Number: {}", anEmployee.employeeNumber);
  std::println("Salary: ${}", anEmployee.salary);
}
