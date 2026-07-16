#include <print>
#include <string>

using namespace std;

string name{"Wang"};

void myFunc(const string &nice) { println("{}", nice); }

const string *nextFunc() { return &name; }
