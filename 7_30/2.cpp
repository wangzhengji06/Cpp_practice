#include <string>

using namespace std;

class Vehicle {
public:
  void set_Color(string value) { color = std::move(value); }

private:
  string color;
};

class Car : public virtual Vehicle {};

class Boat : public virtual Vehicle {};

class AmphibiousCar : public Car, public Boat {};

int main() {
  AmphibiousCar car;
  car.set_Color("red");
}
