#include <print>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n = 100;
  println("从{1}中读取{0}个字节.", n, "files1.txt");

  constexpr auto formatString{"Value: {}"};
  println(formatString, 11);

  // [[fill]align][sign][#][0][width][.precision][L][type]
  int i{42};
  println("|{:5}|", i);
  println("|{:{}}|", i, 7);
  println("|{1}:{0}|", 7, i);

  println("|{:7}|", i);
  println("|{:<7}|", i);
  println("|{:_>7}|", i);
  println("|{:_^7}|", i);

  println("|{:<5}|", i);
  println("|{:<-5}|", -i); // this means that if it is negative it will have -,
                           // and left allgined
  println("{:<+5}", i);    // will have a + for positive number
  println("{:< 5}", i);    // will have a space for positive number

  // enables the alternate formatting rule, like binary, boolean, character,
  // string, pointer, and a lot of floating number cases

  println("|{:#10b}|", i); // 0b10101010

  // floating number precision

  double d{3.1415 / 2.3};
  println("{{:12g}}", d); // 1.36587, g here means it will automatically choose
                          // scientific notation if it is shorter
  println("{:_< 12.2e}",
          d); // this means 2 digit scientifict notation, with wdith 12, left
              // alligned, have space as sign, _ as filler

  // 0 is ignored if there is allginment. it alwyas after any sign and any
  // prefix, but before numbers
  println("{:06d}", i);
  println("{:+06d}", i);
  println("{:06X}", i);
  println("{:#06X}", i);

  // debug ?
  println("|{:?}|", "Hello\tWorld!\n");
  println("|{:?}|", "\"");

  //  [[fill]align][width][n][range-type][:range-underlying-spec]
  // if n is used, it means no bracket
  // m: used for pair and tuple with 2 elements. s:  format as a string ?s:
  // format as escaped string

  vector values{11, 22, 33};

  println("{}", values);
  println("{:n}", values);
  println("{{{:n}}}", values);

  println("{:*^16}", values);
  // you can specify the format of individual element
  println("{::*^16}", values);

  vector chars{'W', 'o', 'r', 'l', 'd', '\t', '!'};
  println("{:?s}", chars);

  pair p{11, 22};

  println("{:m}", p);
}
