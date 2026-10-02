#include <chrono>
#include <print>

using namespace std;

int main() {
  chrono::year_month_day fulldate1{chrono::year{2020} / 6 / 23};
  auto d1{chrono::sys_days{fulldate1}};

  chrono::weekday wd{d1};

  println("{}", wd);
}
