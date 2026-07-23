#pragma once

#include <format>
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

  const std::string &getFirstName() const & { return m_firstName; }
  std::string getFirstName() && { return std::move(m_firstName); }
  void setFirstName(std::string firstName) {
    m_firstName = std::move(firstName);
  }

  const std::string &getLastName() const { return m_lastName; }
  std::string getLastName() && { return std::move(m_lastName); }
  void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

  const std::string &getInitials() const { return m_initials; }
  std::string getInitials() && { return std::move(m_initials); }
  void setInitials(std::string initials) { m_initials = std::move(initials); }

  [[nodiscard]] auto operator<=>(const Person &) const = default;

private:
  std::string m_firstName;
  std::string m_lastName;
  std::string m_initials;
};
