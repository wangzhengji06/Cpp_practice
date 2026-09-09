#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Person {
public:
  explicit Person(string first, string last)
      : m_firstName{std::move(first)}, m_lastName{std::move(last)} {}
  const string &getFirstName() const { return m_firstName; }
  const string &getLastName() const { return m_lastName; }

private:
  string m_firstName;
  string m_lastName;
  int age;
};

ostream &operator<<(ostream &ostream, const Person &person) {
  ostream << person.getFirstName() << " " << person.getLastName();
  return ostream;
}

template <typename InputIter> auto sum(InputIter begin, InputIter end) {
  auto result{*begin};

  for (auto iter{++begin}; iter != end; ++iter) {
    result += *iter;
  }

  return result;
}

template <input_iterator InputIter,
          output_iterator<iter_reference_t<InputIter>> OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target) {
  for (auto iter{begin}; iter != end; ++iter, ++target) {
    *target = *iter;
  }
}

int main() {
  vector<pair<Person, int>> persons;

  persons.emplace_back(Person{"Jack", "Huang"}, 91);
  persons.emplace_back(Person{"Tom", "Liu"}, 13);
  persons.emplace_back(Person{"Amy", "Wang"}, 30);
  persons.emplace_back(Person{"Bob", "Smith"}, 70);
  persons.emplace_back(Person{"John", "Doe"}, 45);

  auto selected{persons | views::transform([](const auto &person) {
                  return person.first.getFirstName() + " " +
                         person.first.getLastName();
                }) |
                views::take(4) | views::common};

  myCopy(selected.begin(), selected.end(),
         ostream_iterator<string>{cout, "\n"});

  auto selected_2{persons | views::transform([](const auto &person) {
                    return person.first.getLastName();
                  }) |
                  views::take(4) | views::common};

  println("{}", selected_2);
}
