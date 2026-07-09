#include <iterator>

char **allocateCharacterBoard(size_t xDimension, size_t yDimension) {
  char **myArray{new char *[xDimension]}; // I create a pointer to a pointer of
                                          // char array, and that pointer points
                                          // to an Array of char pointers
  for (size_t i{0}; i < xDimension; ++i) {
    myArray[i] = new char[yDimension]; // for eachg pointer to char in the array
                                       // of char pointers, I make the pointer
                                       // to char also point to an array of char
  }
  return myArray;
}

int main() {

  // stack can directly do that
  char board[3][3]{};
  board[0][0] = 'X';
  board[2][1] = 'O';

  // heap is different
  char **board{new char[3][3]};

  cha'r
}
