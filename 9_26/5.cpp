#include <memory>
#include <print>

struct NodeA;
struct NodeB;

struct NodeA {
  std::shared_ptr<NodeB> b;
};

struct NodeB {
  std::weak_ptr<NodeA> a;
};

int main() {
  std::weak_ptr<NodeA> weak_a;
  {
    auto a{std::make_shared<NodeA>()};
    auto b{std::make_shared<NodeB>()};
    a->b = b;
    b->a = a;
    weak_a = a;
  }

  std::println("expired: {}", weak_a.expired());
}
