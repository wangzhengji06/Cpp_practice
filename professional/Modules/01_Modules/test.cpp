// it seems that vim cannot read everything clearly
#include <print>
import person;

using namespace std;
int main() {
  Person person{"Kole", "Webb"};
  println("{}, {}", person.getLastName(), person.getFirstName());
}
