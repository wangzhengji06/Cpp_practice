cmake_minimum_required(VERSION 3.25)
project(thread_pool_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TSAN "Build with ThreadSanitizer" ON)

add_executable(example experiments.cpp)

add_executable(thread_pool_demo src/main.cpp)
target_include_directories(thread_pool_demo PRIVATE include)

find_package(Threads REQUIRED)
target_link_libraries(thread_pool_demo PRIVATE Threads::Threads)
target_link_libraries(example PRIVATE Threads::Threads)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(thread_pool_demo PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(example PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(ENABLE_TSAN)
  target_compile_options(thread_pool_demo PRIVATE -fsanitize=thread -g)
  target_link_options(thread_pool_demo PRIVATE -fsanitize=thread)
endif()

if(ENABLE_TSAN)
  target_compile_options(example PRIVATE -fsanitize=thread -g)
  target_link_options(example PRIVATE -fsanitize=thread)
endif()