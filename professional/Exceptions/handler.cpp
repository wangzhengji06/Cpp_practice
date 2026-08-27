#include <exception>
#include <fstream>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

vector<int> readIntegerFile(const string &filename) {
  ifstream inputStream{filename};
  if (inputStream.fail()) {
    const string error{format("Unable to open file {}.", filename)};
    throw invalid_argument{error};
  }

  vector<int> integers;
  int temp;
  while (inputStream >> temp) {
    integers.push_back(temp);
  }

  if (!inputStream.eof()) {
    const string error{format("Unable to read file {}.", filename)};
    throw runtime_error{error};
  }
  return integers;
}

[[noreturn]] void myTerminate() {
  println(cerr, "Uncaught exception!");
  _Exit(1);
}

int main() {
  set_terminate(myTerminate);

  const string filename{"IntegerFile.txt"};
  vector<int> myInts{readIntegerFile(filename)};
  println("{} ", myInts);
}
