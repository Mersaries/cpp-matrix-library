CXX = g++
EFLAGS = -Wall -Wextra -Werror -std=c++17
CFLAGS = $(EFLAGS) -c
OFLAGS = $(EFLAGS) -o
TEST_FLAGS = -lgtest
SRC = $(wildcard s21_*.cc)
OBJ = $(wildcard s21_*.o)
SRC_TEST = test.cc tests/test_*.cc


all: test

s21_matrix_oop.a:
	$(CXX) $(CFLAGS) $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	# ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	$(CXX) $(CFLAGS) $(SRC_TEST) 
	$(CXX) $(OFLAGS) test *.o s21_matrix_oop.a $(TEST_FLAGS)
	./test
	
gcov:
	$(CXX) --coverage $(CFLAGS) $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	$(CXX) $(CFLAGS) $(SRC_TEST) s21_matrix_oop.a
	$(CXX) --coverage $(OFLAGS) test *.o $(TEST_FLAGS)
	./test
	gcovr -r . --html --html-details -o report.html
	# open report.html

check_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cc *.h tests/*.cc
	rm -rf .clang-format

correction_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.cc *.h tests/*.cc
	rm -rf .clang-format

valgrind: s21_matrix_oop.a
	$(CXX) $(CFLAGS) $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	$(CXX) $(CFLAGS) $(SRC_TEST) s21_matrix_oop.a
	$(CXX) $(OFLAGS) test *.o $(TEST_FLAGS)
	valgrind --leak-check=full -s ./test

rebuild: clean all

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.html *.css test

.PHONY:
	all clean test s21_matrix_oop.a rebuild


# all, clean, test, s21_matrix_oop.a


build_cmake:
	rm -rf build
	cmake -B build -S .
	cd build && cmake --build .
	./build/test_matrix