#include <print>

using namespace std;

class Demo {
public:
  int get() { return 5; }
};

int get() { return 10; }

namespace NS {
int get() { return 20; }
} // namespace NS


int main() {
  Demo d;
  println("{}", d.get());
  println("{}", NS::get());
  println("{}", ::get());
  println("{}", get());


}
