
#include <utility>
using namespace std;

template <typename T> class ScopedPtr {
public:
  explicit ScopedPtr(T *pointer) : my_ptr(pointer) {}
  ~ScopedPtr() { delete my_ptr; }
  ScopedPtr(const ScopedPtr &other) = delete;
  ScopedPtr(ScopedPtr &&other) noexcept
      : my_ptr(std::exchange(other.my_ptr, nullptr)) {}
  ScopedPtr &operator=(const ScopedPtr &other) = delete;
  ScopedPtr &operator=(ScopedPtr &&other) noexcept {
    if (this != &other) {
      delete my_ptr;
      my_ptr = std::exchange(other.my_ptr, nullptr);
    }
    return *this;
  }
  T *showPtr() { return my_ptr; }

private:
  T *my_ptr;
};
