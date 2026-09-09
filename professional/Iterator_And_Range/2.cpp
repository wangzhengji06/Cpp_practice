#include <iostream>
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

template <typename InputIter> auto sum(InputIter begin, InputIter end) {
  auto result{*begin};

  for (auto iter{++begin}; iter != end; ++iter) {
    result += *iter;
  }

  return result;
}

int main() {
  vector<pair<Person, int>> persons;

  persons.emplace_back(Person{"Jack", "Huang"}, 91);
  persons.emplace_back(Person{"Tom", "Liu"}, 13);
  persons.emplace_back(Person{"Amy", "Wang"}, 30);
  persons.emplace_back(Person{"Bob", "Smith"}, 70);
  persons.emplace_back(Person{"John", "Doe"}, 45);

  auto ages{persons |
            views::transform([](const auto &person) { return person.second; }) |
            views::filter([](int age) { return age >= 12 && age <= 65; }) |
            views::common};

  const auto count = ranges::distance(ages);

  if (count != 0) {
    const auto total = sum(ages.begin(), ages.end());
    const double average = static_cast<double>(total) / count;

    cout << average << '\n';
  }
}
