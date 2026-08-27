#include <iostream>
#include <source_location>
#include <stacktrace>
#include <string>

using namespace std;

class MyException : public exception {
public:
  explicit MyException(string message,
                       source_location location = source_location::current())
      : m_message{std::move(message)}, m_location{std::move(location)},
        m_stackTrace{stacktrace::current(1)} {
  } // why? because I wnat to skip the constructor

  const char *what() const noexcept override { return m_message.c_str(); }
  virtual const source_location &where() const noexcept { return m_location; }
  virtual const stacktrace &how() const noexcept { return m_stackTrace; }

private:
  string m_message;
  source_location m_location;
  stacktrace m_stackTrace;
};

void doSomething() { throw MyException{"Throwing MyException."}; }

int main() {
  try {
    doSomething();
  } catch (const MyException &e) {
    const auto &location{e.where()};
    println(cerr, "Caught: '{}' at line {} in {}.", e.what(), location.line(),
            location.function_name());
  }
}
