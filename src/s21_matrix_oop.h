#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_
#include <cmath>
#include <exception>
#include <iostream>
#include <string_view>

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  const double eps = 1e-7;

  void CreateMatrix();
  void SwapParamsMatrix(S21Matrix& other);
  bool EqParamsMatrix(const S21Matrix& other);
  double GetMinor(int row, int col);

 public:
  S21Matrix() noexcept;  // Default constructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();  // Destructor

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int get_rows() const noexcept;
  int get_cols() const noexcept;
  void set_rows(int rows);
  void set_cols(int cols);

  // operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int i, int j) &;

  friend S21Matrix operator*(double num, S21Matrix& other);
  friend S21Matrix operator*(S21Matrix& other, double num);
  S21Matrix operator*=(double num);
};

S21Matrix operator*(double num, S21Matrix& other);
S21Matrix operator*(S21Matrix& other, double num);

#endif  // S21_MATRIX_OOP_H_