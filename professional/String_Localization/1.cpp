#include <locale>
#include <print>

using namespace std;

int main() {
  locale userLocale{""};
  auto &facet{use_facet<numpunct<char>>(userLocale)};
  println("Decimal seperator: {}", facet.decimal_point());
}
