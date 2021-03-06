// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
    const int border = 0;
    Matrix_fill_border(mat, border);
    for (int r = 0; r < height; ++r){
        ASSERT_EQUAL(*Matrix_at(mat, r, 0), border);
        ASSERT_EQUAL(*Matrix_at(mat, r, width - 1), border);
    }
    for (int c = 0; c < width; ++c){
        ASSERT_EQUAL(*Matrix_at(mat, 0, c), border);
        ASSERT_EQUAL(*Matrix_at(mat, height - 1, c), border);
    }

    
  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(test_max_min) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    
    const int width = 5;
    const int height = 3;
    const int value = 0;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *Matrix_at(mat, 0, 3) = 9;
    *Matrix_at(mat, 0, 2) = 9;
    *Matrix_at(mat, 0, 1) = 10;
    *Matrix_at(mat, 0, 4) = 8;
    
    ASSERT_EQUAL(Matrix_max(mat), 10);

    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 1, 4), 2);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 1, 5), 8);
    
    delete mat; // delete the Matrix
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
