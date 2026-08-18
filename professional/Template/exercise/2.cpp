#include <concepts>
#include <utility>

using namespace std;

template <integral Key, floating_point Value> class KeyValuePair {
public:
  KeyValuePair(Key key, Value value);
  const Key &getKey() const;
  const Value &getValue() const;
  void setKey(Key key);
  void setValue(Value value);

private:
  Key m_key;
  Value m_value;
};

template <integral Key, floating_point Value>
KeyValuePair<Key, Value>::KeyValuePair(Key key, Value value)
    : m_key(std::move(key)), m_value(std::move(value)) {}

template <integral Key, floating_point Value>
const Key &KeyValuePair<Key, Value>::getKey() const {
  return m_key;
}

template <integral Key, floating_point Value>
const Value &KeyValuePair<Key, Value>::getValue() const {
  return m_value;
}

template <integral Key, floating_point Value>
void KeyValuePair<Key, Value>::setKey(Key key) {
  m_key = std::move(key);
}

template <integral Key, floating_point Value>
void KeyValuePair<Key, Value>::setValue(Value value) {
  m_value = std::move(value);
}
