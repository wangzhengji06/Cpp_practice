#include <concepts>
#include <string>

template <typename T>
concept Cat = requires(T t) { std::to_string(t); };

std::string concat(const Cat auto &t1, const Cat auto &t2) {
  return std::to_string(t1) + std::to_string(t2);
}

std::string concat(const std::string &t1, const std::string &t2) {
  return t1 + t2;
}

std::string concat(const Cat auto &t1, const std::string &t2) {
  return std::to_string(t1) + t2;
}

std::string concat(const std::string &t1, const Cat auto &t2) {
  return t1 + std::to_string(t2);
}
