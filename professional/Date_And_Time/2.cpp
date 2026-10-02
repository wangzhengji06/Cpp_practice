#include <chrono>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  cout << "Please enter a date in the format of yyyy-mm-dd" << "\n";
  string str;
  cin >> str;

  regex r{"(\\d{4})-(0?[1-9]|1[0-2])-(0?[1-9]|[1-2][0-9]|3[0-1])"};
  if (smatch m; regex_match(str, m, r)) {
    int i_year{stoi(m[1])};
    int i_month{stoi(m[2])};
    int i_day{stoi(m[3])};
    chrono::year_month_day fulldate{
        chrono::year{i_year} / chrono::month{static_cast<unsigned>(i_month)} /
        chrono::day{static_cast<unsigned>(i_day)}};
    cout << "You are inputting " << fulldate;
    if (fulldate.ok()) {
      cout << "Valid date\n";
    } else {
      cout << "Invalid date\n";
    }
  }
}
