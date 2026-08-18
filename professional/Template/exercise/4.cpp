#include <concepts>
#include <cstddef>
#include <optional>
using namespace std;

template <std::equality_comparable T>
optional<size_t> Find(const T &value, const T *arr, size_t size) {
  for (size_t i{0}; i < size; ++i) {
    if (arr[i] == value) {
      return i;
    }
  }
  return {};
}
