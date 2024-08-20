#include "../test.h"

TEST(ConstructTest, BaseMatrix1) {
  S21Matrix m = S21Matrix();
  EXPECT_EQ(m.get_cols(), 0);
  EXPECT_EQ(m.get_rows(), 0);
}

TEST(ConstructTest, BaseMatrix2) {
  S21Matrix m = S21Matrix(1, 1);
  EXPECT_EQ(m.get_cols(), 1);
  EXPECT_EQ(m.get_rows(), 1);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix3) {
  S21Matrix m = S21Matrix(2, 2);
  EXPECT_EQ(m.get_cols(), 2);
  EXPECT_EQ(m.get_rows(), 2);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix4) {
  S21Matrix m = S21Matrix(3, 3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix5) {
  S21Matrix m = S21Matrix(5, 5);
  EXPECT_EQ(m.get_cols(), 5);
  EXPECT_EQ(m.get_rows(), 5);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix6) {
  S21Matrix m = S21Matrix(1, 5);
  EXPECT_EQ(m.get_cols(), 5);
  EXPECT_EQ(m.get_rows(), 1);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix7) {
  S21Matrix m = S21Matrix(5, 1);
  EXPECT_EQ(m.get_cols(), 1);
  EXPECT_EQ(m.get_rows(), 5);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix8) {
  S21Matrix m = S21Matrix(100, 98);
  EXPECT_EQ(m.get_cols(), 98);
  EXPECT_EQ(m.get_rows(), 100);
  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(ConstructTest, BaseMatrix9) {
  EXPECT_THROW(S21Matrix(-100, 98), std::string);
  EXPECT_THROW(S21Matrix(100, -98), std::string);
}

TEST(ConstructTest, BaseMatrix10) {
  S21Matrix m = S21Matrix(0, 98);
  EXPECT_EQ(m.get_rows(), 0);
}

TEST(ConstructTest, BaseMatrix11) {
  S21Matrix m = S21Matrix(100, 0);
  EXPECT_EQ(m.get_cols(), 0);
  EXPECT_EQ(m.get_rows(), 100);
}

TEST(ConstructTest, BaseMatrix12) {
  S21Matrix m = S21Matrix(3, 3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  m(1, 1) = 3.14;

  S21Matrix n{m};
  EXPECT_EQ(n.get_cols(), 3);
  EXPECT_EQ(n.get_rows(), 3);
  EXPECT_EQ(n(1, 1), 3.14);
}

TEST(ConstructTest, BaseMatrix13) {
  S21Matrix m = S21Matrix(3, 3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  m(1, 1) = 3.14;

  S21Matrix mnull = S21Matrix();
  S21Matrix n{mnull};
}

TEST(ConstructTest, BaseMatrix14) {
  S21Matrix m(3, 3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  m(1, 1) = 3.14;

  S21Matrix mmove(std::move(m));
  EXPECT_EQ(m.get_cols(), 0);
  EXPECT_EQ(m.get_rows(), 0);
  EXPECT_EQ(mmove.get_cols(), 3);
  EXPECT_EQ(mmove.get_rows(), 3);
  mmove(1, 1) = 3.14;
}

TEST(ConstructTest, BaseMatrix15) {
  S21Matrix m(3, 3);
  EXPECT_ANY_THROW(m(-1, -1));
}

// --------------------------

TEST(GetSetTest, GetSetTest1) {
  S21Matrix m = S21Matrix(1, 1);
  EXPECT_EQ(m.get_cols(), 1);
  EXPECT_EQ(m.get_rows(), 1);
  m.set_cols(3);
  m.set_rows(3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  m(0, 0) = 123;
  EXPECT_EQ(m(0, 0), 123);
}

TEST(GetSetTest, GetSetTest2) {
  S21Matrix m = S21Matrix(2, 1);
  EXPECT_EQ(m.get_cols(), 1);
  EXPECT_EQ(m.get_rows(), 2);
  m(1, 0) = 333;
  m.set_cols(3);
  m.set_rows(3);
  EXPECT_EQ(m.get_cols(), 3);
  EXPECT_EQ(m.get_rows(), 3);
  m(2, 2) = 123;
  EXPECT_EQ(m(1, 0), 333);
}

TEST(GetSetTest, GetSetTest3) {
  S21Matrix m = S21Matrix(2, 1);
  EXPECT_ANY_THROW(m.set_cols(-1));
  EXPECT_ANY_THROW(m.set_rows(-1));
}

TEST(GetSetTest, GetSetTest4) {
  S21Matrix m = S21Matrix(2, 1);
  m.set_rows(4);
  m.set_cols(4);
  EXPECT_EQ(m.get_rows(), 4);
  EXPECT_EQ(m.get_cols(), 4);
}

// ----------------------------

TEST(TransposeTest, TransposeTest1) {
  S21Matrix m = S21Matrix(3, 1);
  S21Matrix n = m.Transpose();

  EXPECT_EQ(n.get_rows(), 1);
  EXPECT_EQ(n.get_cols(), 3);
}

TEST(TransposeTest, TransposeTest2) {
  S21Matrix m = S21Matrix();
  S21Matrix n = m.Transpose();

  EXPECT_EQ(n.get_rows(), 0);
  EXPECT_EQ(n.get_cols(), 0);
}

// -----------------------------

TEST(DeterminantTest, DeterminantTest1) {
  S21Matrix m = S21Matrix(3, 1);

  EXPECT_ANY_THROW(m.Determinant());
}

TEST(DeterminantTest, DeterminantTest2) {
  S21Matrix m = S21Matrix(1, 1);
  m(0, 0) = 4221;

  EXPECT_EQ(m.Determinant(), 4221);
}

TEST(DeterminantTest, DeterminantTest3) {
  S21Matrix m = S21Matrix(3, 3);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 4;
  m(1, 1) = 5;
  m(1, 2) = 6;
  m(2, 0) = 7;
  m(2, 1) = 8;
  m(2, 2) = 9;

  EXPECT_EQ(m.Determinant(), 0);
}

TEST(DeterminantTest, DeterminantTest4) {
  S21Matrix m = S21Matrix(2, 2);
  m(0, 0) = 32;
  m(0, 1) = 4;
  m(1, 0) = 2;
  m(1, 1) = 65;
  printf("DETERMINANT: %lf\n", m.Determinant());
  EXPECT_EQ(m.Determinant(), 2072);
}

// ----------------------------------

TEST(InverseMatrixTest, InverseMatrixTest1) {
  S21Matrix m = S21Matrix(3, 3);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 4;
  m(1, 1) = 5;
  m(1, 2) = 6;
  m(2, 0) = 7;
  m(2, 1) = 8;
  m(2, 2) = 9;

  EXPECT_ANY_THROW(m.InverseMatrix());
}

TEST(InverseMatrixTest, InverseMatrixTest2) {
  S21Matrix m = S21Matrix(3, 3);
  m(0, 0) = 2;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 5;
  m(1, 1) = 5;
  m(1, 2) = 6;
  m(2, 0) = 74;
  m(2, 1) = 8;
  m(2, 2) = 43;
  S21Matrix n = m.InverseMatrix();

  EXPECT_DOUBLE_EQ(n(0, 0), -167.0 / 198.0);
  EXPECT_DOUBLE_EQ(n(0, 1), 31.0 / 99.0);
  EXPECT_DOUBLE_EQ(n(0, 2), 1.0 / 66.0);
  EXPECT_DOUBLE_EQ(n(1, 0), -229.0 / 198.0);
  EXPECT_DOUBLE_EQ(n(1, 1), 68.0 / 99.0);
  EXPECT_DOUBLE_EQ(n(1, 2), -1.0 / 66.0);
  EXPECT_DOUBLE_EQ(n(2, 0), 5.0 / 3.0);
  EXPECT_DOUBLE_EQ(n(2, 1), -2.0 / 3.0);
  EXPECT_DOUBLE_EQ(n(2, 2), 0.0);
}

TEST(InverseMatrixTest, InverseMatrixTest3) {
  S21Matrix m = S21Matrix(1, 1);
  m(0, 0) = 2;

  S21Matrix n = m.InverseMatrix();

  EXPECT_EQ(n(0, 0), 0.5);
}