#pragma once

#include <string>
#include <utility>

template <typename Key, typename Value> class KeyValuePair {
public:
  explicit KeyValuePair(Key key, Value value)
      : m_key{std::move(key)}, m_value{std::move(value)} {}

  const Key &getKey() const { return m_key; }
  void setKey(Key key) { m_key = std::move(key); }

  const Value &getValue() const { return m_value; }
  void setValue(Value value) { m_value = std::move(value); }

private:
  Key m_key;
  Value m_value;
};

template <typename Key> class KeyValuePair<Key, const char *> {
public:
  explicit KeyValuePair(Key key, const char *value)
      : m_key{key}, m_value{value} {}

  const Key &getKey() const { return m_key; }
  void setKey(Key key) { m_key = std::move(key); }

  const std::string &getValue() const { return m_value; }
  void setValue(const char *value) { m_value = value; }

private:
  Key m_key;
  std::string m_value;
};
