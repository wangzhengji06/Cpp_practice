#pragma once

#include "Person.h"
#include <map>
#include <ranges>
#include <string_view>
#include <vector>

class PhoneBook {
public:
  void add(const Person &person, std::string_view &phone) {
    m_phonebook.emplace(person, phone);
  }

  void remove(const Person &person, std::string_view &phone) {
    auto [begin, end]{m_phonebook.equal_range(person)};
    for (auto iter{begin}; iter != end; ++iter) {
      if (iter->second == phone) {
        m_phonebook.erase(iter);
        break;
      }
    }
  }

  std::vector<std::string> check(const Person &person) {
    auto [begin, end]{m_phonebook.equal_range(person)};
    return std::ranges::subrange{begin, end} | std::views::values |
           std::ranges::to<std::vector>();
  }

private:
  std::multimap<Person, std::string> m_phonebook;
};
