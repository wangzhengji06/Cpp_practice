#include <iostream>
#include <string>

using namespace std;

string readName(istream &stream) {
  string name;
  while (stream) {
    int next{stream.get()};
    if (!stream || next == std::char_traits<char>::eof())
      break;
    name += static_cast<char>(next);
  }
  return name;
}
