#include <memory>
#include <print>

int *my_alloc(int value) { return new int{value}; }
void my_free(int *p) { delete p; }

void close_file(FILE *filePtr) {
  if (filePtr == nullptr) {
    return;
  }
  fclose(filePtr);
  std::println("File Closed");
}

int main() {
  std::shared_ptr<int> myIntSmartPtr{my_alloc(42), my_free};
  FILE *f{fopen("data.txt", "w")};
  std::shared_ptr<FILE> filePtr{f, close_file};
}
