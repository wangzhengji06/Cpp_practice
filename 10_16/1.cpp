// Problem: Is there any method that is better than doing some regular
// iteration?
// Initial Reasoning: If you have to do reverse, at least you need to iterate
// those that need to be reversed. The only efficiency effort you can make is to
// reverse k, then jump k, then reverse k, then jump k.
// Investigation: Let's get all the good intervals and bad intervals, I guess.
// Observation:
// I correctly identified that the operation repeats every 2k characters.
// However, my implementation separately tracked complete blocks and remaining
// characters, introducing unnecessary state and off-by-one errors.
// Determination:
// Iterate directly over character indices with a step of 2k. For each starting
// index i, reverse the half-open interval [i, min(i+k, n)). This handles
// complete and incomplete blocks uniformly.

// Reflection
// My initial reasoning correctly identified the periodic structure of the
// algorithm: reverse k characters, skip k characters, and repeat. However,
// instead of translating that periodic structure directly into a loop, I
// changed the representation into a partition of complete intervals and
// remaining characters. This introduced unnecessary state (j, last) and mixed
// coordinate systems, making the implementation vulnerable to incorrect loop
// bounds and off-by-one errors. The key mistake was attempting to explicitly
// model the complete structure of the input when the algorithm only required
// the starting position of the next operation. In future problems, I should
// first identify the minimum state needed for each operation, then determine
// whether a single invariant can cover the boundary cases.

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    int n = s.size();

    for (int i = 0; i < n; i += 2 * k) {
      reverse(s.begin() + i, s.begin() + min(i + k, n));
    }

    return s;
  }
};
