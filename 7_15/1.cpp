#include <memory>
#include <print>
#include <string>
#include <string_view>

using namespace std;

class Person {
public:
  Person() = default; // default constructor
  explicit(true)
      Person(string_view firstname, string_view lastname, string_view initial);
  explicit(true) Person(string_view firstname, string_view lastname);
  void setFirstname(string_view firstname);
  void setLastname(string_view lastname);
  void setInitial(string_view initial);
  string_view getFirstname() const;
  string_view getLastname() const;
  string_view getInitial() const;

private:
  string m_firstname;
  string m_lastname;
  string m_initial;
};

Person::Person(string_view firstname, string_view lastname, string_view initial)
    : m_firstname(firstname), m_lastname(lastname), m_initial(initial) {}

Person::Person(string_view firstname, string_view lastname)
    : Person{firstname, lastname,
             string{firstname.substr(0, 1)} + string{lastname.substr(0, 1)}} {}

void Person::setFirstname(string_view firstname) { m_firstname = firstname; }

void Person::setLastname(string_view lastname) { m_lastname = lastname; }

void Person::setInitial(string_view initial) { m_initial = initial; }

string_view Person::getFirstname() const { return m_firstname; }

string_view Person::getLastname() const { return m_lastname; }

string_view Person::getInitial() const { return m_initial; }

int main() {
  Person p1{"Jack", "Wang"};
  Person p2{"Bob", "Ma", "B.M."};

  auto p3{make_unique<Person>("Alice", "Smith")};

  println("{} {} - initials: {}", p1.getFirstname(), p1.getLastname(),
          p1.getInitial());

  println("{} {} - initials: {}", p2.getFirstname(), p2.getLastname(),
          p2.getInitial());

  println("{} {} - initials: {}", p3->getFirstname(), p3->getLastname(),
          p3->getInitial());
}
