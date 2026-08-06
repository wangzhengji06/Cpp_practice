module;

#include <print>

export module simulator:bike;
import :internals;

using namespace std;
export namespace Simulator {
class BikeSimulator {
public:
  BikeSimulator() { println("Bike simulator created"); }
  void setOdometer(double miles) {
    println("Bike: {}", convertMilesToKm(miles));
  }
};
} // namespace Simulator
