#include <iostream>

struct Book {
  char m_name[20];
  char m_author[10];
  int m_publish_year;
  float m_price;
};

int main() {
  Book book;

  std::cout << "Please input the book information:\n";

  std::cout << "Name: ";
  std::cin >> book.m_name;

  std::cout << "Author: ";
  std::cin >> book.m_author;

  std::cout << "Publish year: ";
  std::cin >> book.m_publish_year;

  std::cout << "Price: ";
  std::cin >> book.m_price;

  std::cout << "\nBook information:\n";
  std::cout << "Name: " << book.m_name << '\n';
  std::cout << "Author: " << book.m_author << '\n';
  std::cout << "Year: " << book.m_publish_year << '\n';
  std::cout << "Price: " << book.m_price << '\n';

  return 0;
}
