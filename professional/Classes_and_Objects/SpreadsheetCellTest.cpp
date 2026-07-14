#include "SpreadsheetCell.h"
#include <memory>
#include <print>

using namespace std;

int main() {
  SpreadsheetCell myCell;

  myCell.setValue(6);
  println("cell 1: {}", myCell.getValue());

  SpreadsheetCell *myCellp{new SpreadsheetCell{}};
  delete myCellp;
  myCellp = nullptr;
}
