#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

int NumberOfDaysBetweenDays(chrono::year_month_day day1,
                            chrono::year_month_day day2) {
  auto d1{chrono::sys_days{day1}};
  auto d2{chrono::sys_days{day2}};
  chrono::days d3{d2 - d1};
  return d3.count();
}

int main() {
  chrono::year_month_day d1{2025y / 11 / 1};
  chrono::year_month_day d2{2025y / 11 / 1};

  cout << "The difference between two days are "
       << NumberOfDaysBetweenDays(d1, d2) << "\n";
}
