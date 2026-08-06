module;

#include <print>

export module simulator;
using namespace std;

export namespace Simulator {
class CarSimulator {
public:
  CarSimulator() { println("CarSimulator() is called."); }
};
class BikeSimulator {
public:
  BikeSimulator() { println("BikeSimulator() is called."); }
};

} // namespace Simulator
