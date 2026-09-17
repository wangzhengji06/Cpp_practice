#include <ranges>

double average(std::span<const double> values) {
  if (values.empty()) {
    return 0.0;
  }

  double sum{};

  for (double value : values) {
    sum += value;
  }

  return sum / values.size();
}
