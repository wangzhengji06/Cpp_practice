#include <chrono>
#include <print>

using namespace std;

int main() {
  auto *Tokyo{chrono::locate_zone("Asia/Tokyo")};
  auto *NewYork{chrono::locate_zone("America/New_York")};
  auto *GMT{chrono::locate_zone("GMT")};

  // Original UTC time
  auto utc{chrono::system_clock::now()};

  // UTC -> Tokyo local time
  auto tokyoLocal{Tokyo->to_local(utc)};

  // Tokyo local time -> UTC/sys_time
  auto fromTokyo{Tokyo->to_sys(tokyoLocal)};

  // -> New York local time
  auto newYorkLocal{NewYork->to_local(fromTokyo)};

  // New York local time -> UTC/sys_time
  auto fromNewYork{NewYork->to_sys(newYorkLocal)};

  // -> GMT local time
  auto gmtLocal{GMT->to_local(fromNewYork)};

  // GMT local time -> sys_time
  auto finalUTC{GMT->to_sys(gmtLocal)};

  println("UTC and GMT represent same instant: {}", utc == finalUTC);
}
}
