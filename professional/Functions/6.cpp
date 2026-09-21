int main() {

  auto power = [](this auto &self, int base, int pow) {
    if (pow == 0) {
      return 1;
    }
    if (pow > 0) {
      return self(base, pow - 1) * base;
    }

    return 1.0 / self(base, -pow);
  };
}
