// Problem: this question wants me to start several thread, of course I need to
// use cache to store the numbers

#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

int calculateFib(std::mutex &my_mutex, vector<int> &fib, int n) {
  lock_guard lock{my_mutex};
  int size = static_cast<int>(fib.size());
  if (size == 0 || size == 1) {
    fib.resize(2);
    fib[0] = 0;
    fib[1] = 1;
    size = 2;
  }
  if (n < fib.size()) {
    return fib[n];
  }
  if (fib.size() <= n) {
    fib.resize(n + 1);
  }
  for (int i = size; i <= n; ++i) {
    if (fib[i] == 0) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
  }
  return fib[n];
}

int main() {
  vector<int> fib;
  mutex my_mutex;
  // start the threads parallely
  future<int> future_1{async(calculateFib, ref(my_mutex), ref(fib), 4)};
  future<int> future_2{async(calculateFib, ref(my_mutex), ref(fib), 7)};
  future<int> future_3{async(calculateFib, ref(my_mutex), ref(fib), 9)};
  future<int> future_4{async(calculateFib, ref(my_mutex), ref(fib), 14)};
  // once all results are avaiable, output them to standard outpout. This means
  // that I need a way to fetch the result'
  int result_1{future_1.get()};
  int result_2{future_2.get()};
  int result_3{future_3.get()};
  int result_4{future_4.get()};

  // Calculate their sum and output.
  auto sum = std::ranges::fold_left(
      vector<int>{result_1, result_2, result_3, result_4}, 0, std::plus<>{});
  std::cout << sum << '\n';
}
