#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(5);
	m1[3][3] = 7;
	m1[1][2] = 15;
	TDynamicMatrix<int> m2(m1);
	ASSERT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(5);
	m1[3][3] = 7;
	m1[1][2] = 15;
	TDynamicMatrix<int> m2(m1);
	m2[4][4] = 4;
	EXPECT_TRUE(!(m1 == m2));
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(5);
  ASSERT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(3);
	m[1][2] = 5;
	ASSERT_EQ(m[1][2], 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(5);
  ASSERT_ANY_THROW(m[-1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m[5]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	size_t size = 5;
	TDynamicMatrix<int> m1(size), m2(size);
	m1[1][1] = 7;
	m2 = m1;
	ASSERT_EQ(m2, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	size_t size1 = 5, size2 = 7;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1 = m2;
	ASSERT_EQ(m1.size(), size2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	size_t size1 = 5, size2 = 7;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m2[3][3] = 3;
	m1 = m2;
	ASSERT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	size_t size = 4;
	TDynamicMatrix<int> m1(size), m2(size);
	m2[3][3] = 3;
	m1[3][3] = 3;
	ASSERT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(3);
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	size_t size1 = 5, size2 = 7;
	TDynamicMatrix<int> m1(size1), m2(size2);
	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size), exp(size);
	m1[2][2] = 4;
	m2[2][2] = 7;
	exp[2][2] = 11;
	ASSERT_EQ(m1 + m2, exp);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5), m2(7);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size), exp(size);
	m1[2][2] = 4;
	m2[2][2] = 7;
	exp[2][2] = -3;
	ASSERT_EQ(m1 - m2, exp);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5), m2(7);
	ASSERT_ANY_THROW(m1 - m2);
}

