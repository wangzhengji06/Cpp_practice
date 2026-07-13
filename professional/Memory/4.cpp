#include <print>
#include <string>

using namespace std;

void fillWithM(string &s) {
  for (auto &character : s) {
    character = 'm';
  }
}
