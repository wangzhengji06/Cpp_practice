#include <cassert>
#include <vector>
using namespace std;

class Matrix {
public:
  Matrix(int row, int col)
      : m_row{row}, m_col{col}, m_data(row, vector<int>(col)) {}
  int getRow() const { return m_row; }
  int getCol() const { return m_col; }
  const vector<vector<int>> &getData() const & { return m_data; }
  vector<vector<int>> &getData() & { return m_data; }

private:
  int m_row;
  int m_col;

  vector<vector<int>> m_data;
};

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  Matrix result{lhs.getRow(), rhs.getCol()};
  const auto &lhs_data{lhs.getData()};
  const auto &rhs_data{rhs.getData()};
  auto &result_data = result.getData();
  for (int i = 0; i < lhs.getRow(); ++i) {
    for (int j = 0; j < rhs.getCol(); ++j) {
      for (int k = 0; k < lhs.getCol(); ++k) {
        result_data[i][j] += lhs_data[i][k] * rhs_data[k][j];
      }
    }
  }
  return result;
}

int main() {
  Matrix a{3, 2};
  Matrix b{2, 3};
  auto &a_data = a.getData();
  auto &b_data = b.getData();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      a_data[i][j] = i;
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      b_data[i][j] = j;
    }
  }

  Matrix c = a * b;
  const auto &c_data = c.getData();
  assert(c_data[0][0] == 0);
  assert(c_data[0][1] == 0);
  assert(c_data[0][2] == 0);

  assert(c_data[1][0] == 0);
  assert(c_data[1][1] == 2);
  assert(c_data[1][2] == 4);

  assert(c_data[2][0] == 0);
  assert(c_data[2][1] == 4);
  assert(c_data[2][2] == 8);
}
