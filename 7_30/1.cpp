#include <memory>
#include <print>

using namespace std;

class Animal {
public:
  virtual void makeSound() { println("I am an animal!"); }
};

class Dog : public Animal {
public:
  virtual void makeSound() override { println("I am a dog!"); }
};

class Cat : public Animal {
public:
  virtual void makeSound() override { println("I am a cat!"); }
};

int main() {
  Dog dog;
  Cat cat;
  Animal &dog_ref{dog};
  Animal &cat_ref{cat};

  dog.makeSound();
  cat.makeSound();
}
