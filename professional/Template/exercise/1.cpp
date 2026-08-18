#include <string>
#include <utility>

using namespace std;

template <typename Key, typename Value> class KeyValuePair {
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

template <typename Key, typename Value>
KeyValuePair<Key, Value>::KeyValuePair(Key key, Value value)
    : m_key(std::move(key)), m_value(std::move(value)) {}

template <typename Key, typename Value>
const Key &KeyValuePair<Key, Value>::getKey() const {
  return m_key;
}

template <typename Key, typename Value>
const Value &KeyValuePair<Key, Value>::getValue() const {
  return m_value;
}

template <typename Key, typename Value>
void KeyValuePair<Key, Value>::setKey(Key key) {
  m_key = std::move(key);
}

template <typename Key, typename Value>
void KeyValuePair<Key, Value>::setValue(Value value) {
  m_value = std::move(value);
}

template <> class KeyValuePair<const char *, const char *> {
public:
  KeyValuePair(const char *key, const char *value);
  const string &getKey() const;
  const string &getValue() const;
  void setKey(const char *key);
  void setValue(const char *value);

private:
  string m_key;
  string m_value;
};

KeyValuePair<const char *, const char *>::KeyValuePair(const char *key,
                                                       const char *value)
    : m_key(key), m_value(value) {}

const string &KeyValuePair<const char *, const char *>::getKey() const {
  return m_key;
}

const string &KeyValuePair<const char *, const char *>::getValue() const {
  return m_value;
}

void KeyValuePair<const char *, const char *>::setKey(const char *key) {
  m_key = key;
}

void KeyValuePair<const char *, const char *>::setValue(const char *value) {
  m_value = value;
}

int main() {
  KeyValuePair<std::string, std::string> kv{"John Doe", "New York"};
  KeyValuePair kv2{"John Doe", "New York"};
}
