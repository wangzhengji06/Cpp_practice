#include <string>
#include <unordered_set>

using namespace std;

bool check(unordered_set<string> &my_set, const string &key) {
  if (my_set.contains(key)) {
    my_set.erase(key);
    return true;
  } else {
    return false;
  }
}
