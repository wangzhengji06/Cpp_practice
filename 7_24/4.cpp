#include <iostream>

class BankAccount {
public:
  explicit BankAccount(int id) : id{id} {}

  static void printInfo(const BankAccount &account) {
    std::cout << "Account ID: " << account.id << '\n';
  }

private:
  int id;
};

int main() {
  BankAccount account{12345};

  BankAccount::printInfo(account);
}
