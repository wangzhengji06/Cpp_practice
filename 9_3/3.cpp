template <typename T> const T &max(const T &a, const T &b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int a = max(3, 5);
  float f = max(1.0f, 2.3f);
  char c = max('a', 'b');
}
