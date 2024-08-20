#include "../test.h"

TEST(SumTest, SumMatrix1) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m2.SumMatrix(m1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(m1(i, j), 0);
      EXPECT_EQ(m2(i, j), 0);
    }
  }
}

TEST(SumTest, SumMatrix2) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 1;
  m1(0, 2) = 2;
  m1(2, 0) = 3;

  m2.SumMatrix(m1);

  EXPECT_EQ(m2(0, 0), 1);
  EXPECT_EQ(m2(0, 2), 2);
  EXPECT_EQ(m2(2, 0), 3);
}

TEST(SumTest, SumMatrix3) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 999;
  m1(0, 2) = 999;
  m1(2, 0) = 999;

  m2(0, 0) = 0.55;
  m2(0, 2) = 0.55;
  m2(2, 0) = 0.55;

  m2.SumMatrix(m1);

  EXPECT_EQ(m2(0, 0), 999.55);
  EXPECT_EQ(m2(0, 2), 999.55);
  EXPECT_EQ(m2(2, 0), 999.55);
}

TEST(SumTest, SumMatrix4) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2.SumMatrix(m1);

  EXPECT_EQ(m2(0, 0), 1123.3456);
}

TEST(SumTest, SumMatrix5) {
  S21Matrix m1(1, 1);
  S21Matrix m2(3, 1);

  EXPECT_ANY_THROW(m2.SumMatrix(m1));
}

TEST(SumTest, SumMatrix6) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2 = m2 + m1;

  EXPECT_EQ(m2(0, 0), 1123.3456);
}

TEST(SumTest, SumMatrix7) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2 += m1;

  EXPECT_EQ(m2(0, 0), 1123.3456);
}

TEST(SumTest, SumMatrix8) {
  S21Matrix m1(1, 1);
  S21Matrix m2(3, 1);

  EXPECT_ANY_THROW(m2 += m1);
  EXPECT_ANY_THROW(m2 = m2 + m1);
}

// -------------------

TEST(SubTest, SubMatrix1) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m2.SubMatrix(m1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(m1(i, j), 0);
      EXPECT_EQ(m2(i, j), 0);
    }
  }
}

TEST(SubTest, SubMatrix2) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  m1(0, 0) = 999;
  m1(0, 2) = 999;
  m1(2, 0) = 999;
  m2(0, 0) = 0.55;
  m2(0, 2) = 0.55;
  m2(2, 0) = 0.55;
  m2.SubMatrix(m1);

  EXPECT_EQ(m2(0, 0), -998.45);
  EXPECT_EQ(m2(0, 2), -998.45);
  EXPECT_EQ(m2(2, 0), -998.45);
}

TEST(SubTest, SubMatrix3) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2.SubMatrix(m1);

  EXPECT_EQ(m2(0, 0), -876.6544);
}

TEST(SubTest, SubMatrix4) {
  S21Matrix m1(1, 1);
  S21Matrix m2(3, 1);

  EXPECT_ANY_THROW(m2.SubMatrix(m1));
}

TEST(SubTest, SubMatrix5) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2 = m2 - m1;

  EXPECT_EQ(m2(0, 0), -876.6544);
}

TEST(SubTest, SubMatrix6) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 1000;
  m2(0, 0) = 123.3456;

  m2 -= m1;

  EXPECT_EQ(m2(0, 0), -876.6544);
}

TEST(SubTest, SubMatrix7) {
  S21Matrix m1(1, 1);
  S21Matrix m2(3, 1);

  EXPECT_ANY_THROW(m2 -= m1);
  EXPECT_ANY_THROW(m2 = m2 - m1);
}

// -------------------------------------

TEST(EqualTest, EqualTest1) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(2, 1);

  EXPECT_EQ(m.EqMatrix(n), true);
}

TEST(EqualTest, EqualTest2) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(2, 1);
  n(1, 0) = 23;

  EXPECT_EQ(m.EqMatrix(n), false);
}

TEST(EqualTest, EqualTest3) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(1, 1);

  EXPECT_ANY_THROW(m.EqMatrix(n));
}

TEST(EqualTest, EqualTest4) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(1, 1);

  EXPECT_ANY_THROW(m == n);
}

TEST(EqualTest, EqualTest5) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(2, 1);
  n(1, 0) = 23;

  EXPECT_EQ(m == n, false);
}

TEST(EqualTest, EqualTest6) {
  S21Matrix m = S21Matrix(2, 1);
  S21Matrix n = S21Matrix(1, 2);

  EXPECT_ANY_THROW(m == n);
}

TEST(EqualTest, EqualTest7) {
  S21Matrix m = S21Matrix(1, 2);
  S21Matrix n = S21Matrix(2, 1);

  EXPECT_ANY_THROW(m == n);
}

// -------------------------------

TEST(MulNumberTest, MulNumberTest1) {
  S21Matrix m = S21Matrix(2, 1);

  m.MulNumber(23.5);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(MulNumberTest, MulNumberTest2) {
  S21Matrix m = S21Matrix(2, 1);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      m(i, j) = 1;
    }
  }

  m.MulNumber(23.5);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 23.5);
    }
  }
}

TEST(MulNumberTest, MulNumberTest3) {
  S21Matrix m = S21Matrix(2, 1);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      m(i, j) = 1;
    }
  }

  m = m * 23.5;

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 23.5);
    }
  }
}

TEST(MulNumberTest, MulNumberTest4) {
  S21Matrix m = S21Matrix(2, 1);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      m(i, j) = 1;
    }
  }

  m = 23.5 * m;

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 23.5);
    }
  }
}

TEST(MulNumberTest, MulNumberTest5) {
  S21Matrix m = S21Matrix(2, 1);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      m(i, j) = 1;
    }
  }

  m *= 23.5;

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 23.5);
    }
  }
}

// -----------------------------------------------

TEST(MulMatrixTest, MulMatrixTest1) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(2, 2);

  m(0, 0) = 1;
  m(0, 1) = 1;
  m(1, 0) = 1;
  m(1, 1) = 1;

  m.MulMatrix(n);

  for (int i = 0; i < m.get_rows(); i++) {
    for (int j = 0; j < m.get_cols(); j++) {
      EXPECT_EQ(m(i, j), 0);
    }
  }
}

TEST(MulMatrixTest, MulMatrixTest2) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(2, 2);

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  n(0, 0) = 5;
  n(0, 1) = 6;
  n(1, 0) = 7;
  n(1, 1) = 8;

  m.MulMatrix(n);

  EXPECT_EQ(m(0, 0), 19);
  EXPECT_EQ(m(0, 1), 22);
  EXPECT_EQ(m(1, 0), 43);
  EXPECT_EQ(m(1, 1), 50);
}

TEST(MulMatrixTest, MulMatrixTest3) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(1, 3);

  EXPECT_ANY_THROW(m.MulMatrix(n));
}

TEST(MulMatrixTest, MulMatrixTest4) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(1, 3);

  EXPECT_ANY_THROW(m = m * n);
  EXPECT_ANY_THROW(m *= n);
}

TEST(MulMatrixTest, MulMatrixTest5) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(2, 2);

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  n(0, 0) = 5;
  n(0, 1) = 6;
  n(1, 0) = 7;
  n(1, 1) = 8;

  m = m * n;

  EXPECT_EQ(m(0, 0), 19);
  EXPECT_EQ(m(0, 1), 22);
  EXPECT_EQ(m(1, 0), 43);
  EXPECT_EQ(m(1, 1), 50);
}

TEST(MulMatrixTest, MulMatrixTest6) {
  S21Matrix m = S21Matrix(2, 2);
  S21Matrix n = S21Matrix(2, 2);

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  n(0, 0) = 5;
  n(0, 1) = 6;
  n(1, 0) = 7;
  n(1, 1) = 8;

  m *= n;

  EXPECT_EQ(m(0, 0), 19);
  EXPECT_EQ(m(0, 1), 22);
  EXPECT_EQ(m(1, 0), 43);
  EXPECT_EQ(m(1, 1), 50);
}