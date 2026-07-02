#include <compare>
#include <iostream>
#include <print>
#include <string>

using namespace std;

int main() {
  string s1, s2;

  println("Please enter the first string:");
  getline(cin, s1);

  println("Please enter the second string:");
  getline(cin, s2);

  if (is_lt(s1 <=> s2)) {
    println("{}\n{}", s1, s2);
  } else {
    println("{}\n{}", s2, s1);
  }
}
