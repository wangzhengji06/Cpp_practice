module;

#include <print>

export module simulator:car;
import :internals;

using namespace std;
export namespace Simulator {
class CarSimulator {
public:
  CarSimulator() { println("Car simulator created"); }
  void setOdometer(double miles) {
    println("Car: {}", convertMilesToKm(miles));
  }
};
} // namespace Simulator
