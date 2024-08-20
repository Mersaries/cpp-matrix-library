#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 0 || cols < 0) {
    throw std::string("Invalid argument!");
  }
  if (rows == 0 && cols == 0) {
    matrix_ = nullptr;
  } else {
    CreateMatrix();
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (other.matrix_) {
    if (other.get_rows() > 0 && other.get_cols() > 0) {
      this->CreateMatrix();
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] = other.matrix_[i][j];
        }
      }
    }
  } else {
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!EqParamsMatrix(other)) {
    throw "different matrix dimensions";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!EqParamsMatrix(other)) {
    throw "different matrix dimensions!";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (!EqParamsMatrix(other)) {
    throw "Invalid argument!";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > eps) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw "first matrix cols is not equal second matrix rows!";
  }

  S21Matrix tmp(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        tmp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  SwapParamsMatrix(tmp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix tMatrix(cols_, rows_);
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        tMatrix.matrix_[j][i] = matrix_[i][j];
      }
    }
  } else {
    tMatrix.cols_ = 0;
    tMatrix.rows_ = 0;
    tMatrix.matrix_ = nullptr;
  }

  return tMatrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) throw "the matrix is not square";
  S21Matrix comp(rows_, cols_);
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        comp.matrix_[i][j] = std::pow(-1, i + j) * this->GetMinor(i, j);
      }
    }
  }

  return comp;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw "the matrix is not square";
  }
  double det = 0;
  if (matrix_) {
    if (rows_ < 1) {
      throw "the matrix is not correct";
    } else if (rows_ == 1) {
      det = matrix_[0][0];
    } else {
      S21Matrix algs = this->CalcComplements();
      for (int i = 0; i < rows_; i++) {
        det = det + matrix_[i][0] * algs.matrix_[i][0];
      }
    }
  }

  return det;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = 0;
  det = Determinant();
  if (std::fabs(det) <= eps) throw "matrix determinant is 0";

  S21Matrix inv(rows_, cols_);
  if (rows_ == 1) {
    inv.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    S21Matrix transp = Transpose();
    S21Matrix comp = transp.CalcComplements();
    comp.MulNumber(1.0 / det);
    return comp;
  }

  return inv;
}

int S21Matrix::get_cols() const noexcept { return cols_; }

int S21Matrix::get_rows() const noexcept { return rows_; }

void S21Matrix::set_cols(int cols) {
  if (cols < 0) {
    throw "negative cols";
  }

  if (cols_ != cols) {
    S21Matrix tmp(rows_, cols);
    int minCols = std::min(cols_, cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < minCols; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
    //  *this = std::move(tmp);
    this->SwapParamsMatrix(tmp);
  }
}

void S21Matrix::set_rows(int rows) {
  if (rows < 0) {
    throw "negative rows";
  }

  if (rows_ != rows) {
    S21Matrix tmp(rows, cols_);
    int minRows = std::min(rows_, rows);
    for (int i = 0; i < minRows; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
    // *this = std::move(tmp);
    this->SwapParamsMatrix(tmp);
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix tmp(other);
  this->set_rows(other.get_rows());
  this->set_cols(other.get_cols());
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = tmp(i, j);
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

double& S21Matrix::operator()(int i, int j) & {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw "index is outside the matrix";
  }
  return matrix_[i][j];
}

double S21Matrix::GetMinor(int row, int col) {
  if (cols_ != rows_) {
    throw "the matrix is not square";
  }
  if (row < 0 || row > rows_ || col < 0 || col > cols_) {
    throw "incorrect element index";
  }
  double minor = 0;
  if (matrix_) {
    if (rows_ == 2 && cols_ == 2) {
      minor = matrix_[1 - row][1 - col];
    } else {
      S21Matrix tmp(rows_ - 1, cols_ - 1);
      int tmpRow = 0, tmpCol = 0;
      for (int i = 0; i < tmp.get_rows(); i++) {
        for (int j = 0; j < tmp.get_cols(); j++) {
          tmpRow = i;
          tmpCol = j;
          if (tmpRow >= row) {
            tmpRow++;
          }
          if (tmpCol >= col) {
            tmpCol++;
          }
          tmp.matrix_[i][j] = matrix_[tmpRow][tmpCol];
        }
      }
      for (int i = 0; i < tmp.rows_; i++) {
        minor += std::pow(-1, i) * tmp.matrix_[i][0] * tmp.GetMinor(i, 0);
      }
    }
  }

  return minor;
}

bool S21Matrix::EqParamsMatrix(const S21Matrix& other) {
  if (cols_ == other.cols_ && rows_ == other.rows_) {
    return true;
  } else {
    return false;
  }
}

void S21Matrix::CreateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::SwapParamsMatrix(S21Matrix& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix operator*(double num, S21Matrix& other) {
  S21Matrix tmp(other);
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix operator*(S21Matrix& other, double num) {
  S21Matrix tmp(other);
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}
