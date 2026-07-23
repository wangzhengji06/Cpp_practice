#include "Person.h"

#include <format>
#include <memory>
#include <utility>

class Person::Impl {
public:
  explicit Impl(std::string firstName, std::string lastName);

  const std::string &getFirstName() const;
  const std::string &getLastName() const;
  const std::string &getInitials() const;

private:
  std::string m_firstName;
  std::string m_lastName;
  std::string m_initials;
};

Person::Impl::Impl(std::string firstName, std::string lastName)
    : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)},
      m_initials{std::format("{}{}", m_firstName[0], m_lastName[0])} {}

const std::string &Person::Impl::getFirstName() const { return m_firstName; }

const std::string &Person::Impl::getLastName() const { return m_lastName; }

const std::string &Person::Impl::getInitials() const { return m_initials; }

Person::Person(std::string firstName, std::string lastName)
    : m_impl{
          std::make_unique<Impl>(std::move(firstName), std::move(lastName))} {}

Person::Person(const Person &other)
    : m_impl{std::make_unique<Impl>(*other.m_impl)} {}

Person &Person::operator=(const Person &other) {
  if (this == &other) {
    return *this;
  }

  m_impl = std::make_unique<Impl>(*other.m_impl);
  return *this;
}

Person::Person(Person &&other) noexcept = default;

Person &Person::operator=(Person &&other) noexcept = default;

Person::~Person() = default;

const std::string &Person::getFirstName() const {
  return m_impl->getFirstName();
}

const std::string &Person::getLastName() const { return m_impl->getLastName(); }

const std::string &Person::getInitials() const { return m_impl->getInitials(); }
