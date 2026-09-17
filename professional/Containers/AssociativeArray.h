#pragma once

#include <format>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

template <typename T> class AssociativeArray final {
public:
  T &operator[](std::string_view key);
  const T &operator[](std::string_view key) const;

private:
  class Element {
  public:
    explicit Element(std::string key, T value)
        : m_key{std::move(key)}, m_value{std::move(value)} {}
    std::string m_key;
    T m_value;
  };

  std::vector<Element> m_data;
};

template <typename T> T &AssociativeArray<T>::operator[](std::string_view key) {
  for (auto &element : m_data) {
    if (element.m_key == key) {
      return element.m_value;
    }
  }

  m_data.push_back(Element{std::string{key}, T{}});
  return m_data.back().m_value;
}

template <typename T>
const T &AssociativeArray<T>::operator[](std::string_view key) const {
  for (auto &element : m_data) {
    if (element.m_key == key) {
      return element.m_value;
    }
  }
  throw std::invalid_argument{
      std::format("Key '{}' doesn't exist.", std::string{key})};
}
