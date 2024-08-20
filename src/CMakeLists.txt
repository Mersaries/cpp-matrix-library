message("--- Тестовая сборка проекта ---")

cmake_minimum_required(VERSION 3.20)

project(S21Matrix_Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_COMPILER gcc)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# FetchContent_MakeAvailable(googletest)

set(matrix
    s21_matrix_oop.h
    s21_matrix_oop.cc)

add_library(s21_matrix_oop STATIC s21_matrix_oop.h s21_matrix_oop.cc)

set(HEADERS
    test.h
    )

set(SOURCES
    test.cc
    tests/test_base.cc
    tests/test_operation.cc)

# add_executable(test_matrix ${SOURCES})

# target_link_libraries(test_matrix 
#                         PUBLIC s21_matrix_oop
#                         PUBLIC GTest::gtest_main)

# include(GoogleTest)
# gtest_discover_tests(test_matrix)

include(GoogleTest)
add_executable(test_matrix ${SOURCES})
# gtest_add_tests(TARGET test_matrix)
target_link_libraries(test_matrix 
                        PUBLIC s21_matrix_oop
                        PUBLIC gtest)