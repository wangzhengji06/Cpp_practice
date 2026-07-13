namespace Math {
double add(double value1, double value2) { return value1 + value2; }
double substract(double value1, double value2) { return value1 - value2; }
} // namespace Math

int main() {
  Math::add(2.0, 3.0);
  Math::substract(2.0, 3.0);
}
