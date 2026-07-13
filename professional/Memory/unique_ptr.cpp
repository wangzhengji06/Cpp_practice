#include <memory>
class Simple {
public:
  void go() {};
};

void notLeaky() {
  auto mySimpleSmartPtr{std::make_unique<Simple>()};
  mySimpleSmartPtr->go();
}

int *my_alloc(int value) { return new int{value}; }

void my_free(int *p) { delete p; }

int main() {
  std::unique_ptr<int, decltype(&my_free)> myIntSmartPtr{my_alloc(42), my_free};
}
