#include <memory>
#include <print>

using namespace std;

class Animal {
public:
  virtual void makeSound() const = 0;
  virtual ~Animal() = default;
};

void Animal::makeSound() const {
  println("I am making sound now, and I am....");
}

class Dog : public Animal {
  virtual void makeSound() const override {
    Animal::makeSound();
    println("a dog!");
  }
};

class Cat : public Animal {
  virtual void makeSound() const override {
    Animal::makeSound();
    println("a cat!");
  }
};

int main() {
  unique_ptr<Animal> dog = make_unique<Dog>();
  unique_ptr<Animal> cat = make_unique<Cat>();
  dog->makeSound();
  cat->makeSound();
}
