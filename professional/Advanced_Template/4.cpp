#include <vector>

using namespace std;

template <typename T, typename... Args>
void push_back_values(std::vector<T> &vec, const Args &...args) {
  (vec.push_back(args), ...);
}

template <typename T, typename... Args>
void insert_values(std::vector<T> &vec, const Args &...args) {
  vec.insert(vec.end(), {args...});
}
