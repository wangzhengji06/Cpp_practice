#pragma once

#include <cstring>
#include <format>
#include <iostream>
#include <print>
#include <string>
#include <utility>

class Person {
public:
  explicit Person(std::string firstName, std::string lastName)
      : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)} {
    m_initials = std::format("{}{}", m_firstName[0], m_lastName[0]);
  }

  Person() = default;

  explicit Person(std::string firstName, std::string lastName,
                  std::string initials)
      : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)},
        m_initials{std::move(initials)} {}

  const std::string &getFirstName() const { return m_firstName; }
  void setFirstName(std::string firstName) {
    m_firstName = std::move(firstName);
  }

  const std::string &getLastName() const { return m_lastName; }
  void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

  const std::string &getInitials() const { return m_initials; }
  void setInitials(std::string initials) { m_initials = std::move(initials); }

  void output(std::ostream &output) const {
    std::println(output, "{} {} ({})", getFirstName(), getLastName(),
                 getInitials());
  }

  [[nodiscard]] auto operator<=>(const Person &) const = default;

  operator std::string() const {
    return std::format("{} {}", getFirstName(), getLastName());
  }

private:
  std::string m_firstName;
  std::string m_lastName;
  std::string m_initials;
};

std::ostream &operator<<(std::ostream &ostr, const Person &p) {
  ostr << p.getFirstName() << ' ' << p.getLastName();
  return ostr;
}

std::istream &operator>>(std::istream &istr, Person &p) {
  std::string firstname, lastname;
  istr >> firstname >> lastname;
  p = Person{firstname, lastname};
  return istr;
}

Person operator""_p(const char *str, std::size_t len) {
  std::string_view sv{str, len};
  auto space = sv.find(' ');
  if (space == std::string_view::npos) {
    throw std::invalid_argument{"Person must contain first and last name"};
  }
  std::string firstName{sv.substr(0, space)};
  std::string lastName{sv.substr(space + 1)};
  return Person{std::move(firstName), std::move(lastName)};
}
