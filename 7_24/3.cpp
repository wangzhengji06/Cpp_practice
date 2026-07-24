#include <print>

using namespace std;

class Counter {
public:
  Counter() { ++count; }
  static int getCount() { return count; }

private:
  inline static int count = 0;
};

int main() {
  Counter counter;
  println("The current count is : {}", Counter::getCount());
  Counter counter2;
  println("The current count is: {}", counter.getCount());
  println("The current count is： {}", counter2.getCount());
}
