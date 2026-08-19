class Base {
public:
  const int &Give() const { return data; }

private:
  const int data = 5;
};

int main() {
  Base base{};
  int &nice = const_cast<int &>(base.Give());
}
