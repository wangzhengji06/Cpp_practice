

enum class State { Unknown, Started, Finished };
enum class Error { None, BadInput, DiskFull, Unknown };

int main() {
  State mystate{State::Unknown};
  mystate = State::Finished;
}
