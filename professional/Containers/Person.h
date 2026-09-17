#pragma once

#include <format>
#include <iomanip>
#include <iostream>
#include <sstream>
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

inline std::ostream &operator<<(std::ostream &os, const Person &person) {
  os << std::quoted(person.getFirstName()) << std::quoted(person.getLastName())
     << std::quoted(person.getInitials());

  return os;
}

inline std::istream &operator>>(std::istream &is, Person &person) {
  std::string firstName, lastName, initials;
  is >> std::quoted(firstName) >> std::quoted(lastName) >>
      std::quoted(initials);

  person.setFirstName(std::move(firstName));
  person.setLastName(std::move(lastName));
  person.setInitials(std::move(initials));

  return is;
}

inline Person operator""_p(const char *s, std::size_t) {
  std::istringstream input{s};

  std::string firstName, lastName;

  input >> firstName;
  input >> std::ws;

  getline(input, lastName);

  return Person{std::move(firstName), std::move(lastName)};
}
