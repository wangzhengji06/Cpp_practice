#include <string>
#include <string_view>

using namespace std;

string extractExtension(string_view filename) {
  return string{filename.substr(filename.rfind('.'))};
}

int main() {
  string str{"Hello"};
  string_view sv{"world"};
  auto result { str + string{sv} };


}
