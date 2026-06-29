cmake_minimum_required(VERSION 3.28)
project(EmployeeModuleTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(employee_test)

target_sources(employee_test
  PRIVATE
    EmployeeTest.cpp
    Employee.cpp
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
      Employee.cppm
)
