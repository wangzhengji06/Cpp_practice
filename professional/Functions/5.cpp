#include <functional>

class Processor {
public:
  explicit Processor(std::function<int(int)> myfunc) : m_myfunc(myfunc) {}
  auto operator()(int i) const { return m_myfunc(i); }

private:
  std::function<int(int)> m_myfunc;
};
