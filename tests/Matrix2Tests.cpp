
#include <gtest/gtest.h>

#include "geom/Matrix2.hpp"

TEST(Matrix2, DefaultConstructor) {
  geom::Matrix2i mat2;
  EXPECT_EQ(mat2.values[0], 0);
  EXPECT_EQ(mat2.values[1], 0);
  EXPECT_EQ(mat2.values[2], 0);
  EXPECT_EQ(mat2.values[3], 0);
  EXPECT_EQ(mat2.values[4], 0);
  EXPECT_EQ(mat2.values[5], 0);
  EXPECT_EQ(mat2.values[6], 0);
  EXPECT_EQ(mat2.values[7], 0);
  EXPECT_EQ(mat2.values[8], 0);
}
TEST(Matrix2, ScalarConstructor) {
  geom::Matrix2i mat2(1,2,3,4,5,6,7,8,9);
  EXPECT_EQ(mat2.values[0], 1);
  EXPECT_EQ(mat2.values[1], 4);
  EXPECT_EQ(mat2.values[2], 7);
  EXPECT_EQ(mat2.values[3], 2);
  EXPECT_EQ(mat2.values[4], 5);
  EXPECT_EQ(mat2.values[5], 8);
  EXPECT_EQ(mat2.values[6], 3);
  EXPECT_EQ(mat2.values[7], 6);
  EXPECT_EQ(mat2.values[8], 9);
}
TEST(Matrix2, CopyConstructor) {
  geom::Matrix2i mat1(1,2,3,4,5,6,7,8,9);
  geom::Matrix2i mat2(mat1);
  EXPECT_EQ(mat2.values[0], mat1.values[0]);
  EXPECT_EQ(mat2.values[1], mat1.values[1]);
  EXPECT_EQ(mat2.values[2], mat1.values[2]);
  EXPECT_EQ(mat2.values[3], mat1.values[3]);
  EXPECT_EQ(mat2.values[4], mat1.values[4]);
  EXPECT_EQ(mat2.values[5], mat1.values[5]);
  EXPECT_EQ(mat2.values[6], mat1.values[6]);
  EXPECT_EQ(mat2.values[7], mat1.values[7]);
  EXPECT_EQ(mat2.values[8], mat1.values[8]);
}
TEST(Matrix2, ConvertConstructor1) {
  geom::Matrix2i mat1(1,2,3,4,5,6,7,8,9);
  geom::Matrix2d mat2(mat1);
  EXPECT_EQ(mat2.values[0], static_cast<double>(mat1.values[0]));
  EXPECT_EQ(mat2.values[1], static_cast<double>(mat1.values[1]));
  EXPECT_EQ(mat2.values[2], static_cast<double>(mat1.values[2]));
  EXPECT_EQ(mat2.values[3], static_cast<double>(mat1.values[3]));
  EXPECT_EQ(mat2.values[4], static_cast<double>(mat1.values[4]));
  EXPECT_EQ(mat2.values[5], static_cast<double>(mat1.values[5]));
  EXPECT_EQ(mat2.values[6], static_cast<double>(mat1.values[6]));
  EXPECT_EQ(mat2.values[7], static_cast<double>(mat1.values[7]));
  EXPECT_EQ(mat2.values[8], static_cast<double>(mat1.values[8])); 
}
TEST(Matrix2, ConvertConstructor2) {
  geom::Matrix2d mat1(1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9);
  geom::Matrix2i mat2(mat1);
  EXPECT_EQ(mat2.values[0], static_cast<int>(mat1.values[0]));
  EXPECT_EQ(mat2.values[1], static_cast<int>(mat1.values[1]));
  EXPECT_EQ(mat2.values[2], static_cast<int>(mat1.values[2]));
  EXPECT_EQ(mat2.values[3], static_cast<int>(mat1.values[3]));
  EXPECT_EQ(mat2.values[4], static_cast<int>(mat1.values[4]));
  EXPECT_EQ(mat2.values[5], static_cast<int>(mat1.values[5]));
  EXPECT_EQ(mat2.values[6], static_cast<int>(mat1.values[6]));
  EXPECT_EQ(mat2.values[7], static_cast<int>(mat1.values[7]));
  EXPECT_EQ(mat2.values[8], static_cast<int>(mat1.values[8])); 
}
TEST(Matrix2, Assignment) {
  geom::Matrix2i mat1(1,2,3,4,5,6,7,8,9);
  geom::Matrix2i mat2;
  mat2 = mat1;
  EXPECT_EQ(mat2.values[0], mat1.values[0]);
  EXPECT_EQ(mat2.values[1], mat1.values[1]);
  EXPECT_EQ(mat2.values[2], mat1.values[2]);
  EXPECT_EQ(mat2.values[3], mat1.values[3]);
  EXPECT_EQ(mat2.values[4], mat1.values[4]);
  EXPECT_EQ(mat2.values[5], mat1.values[5]);
  EXPECT_EQ(mat2.values[6], mat1.values[6]);
  EXPECT_EQ(mat2.values[7], mat1.values[7]);
  EXPECT_EQ(mat2.values[8], mat1.values[8]);
}
TEST(Matrix2, ConvertAssignment1) {
  geom::Matrix2i mat1(1,2,3,4,5,6,7,8,9);
  geom::Matrix2d mat2;
  mat2 = mat1;
  EXPECT_EQ(mat2.values[0], static_cast<double>(mat1.values[0]));
  EXPECT_EQ(mat2.values[1], static_cast<double>(mat1.values[1]));
  EXPECT_EQ(mat2.values[2], static_cast<double>(mat1.values[2]));
  EXPECT_EQ(mat2.values[3], static_cast<double>(mat1.values[3]));
  EXPECT_EQ(mat2.values[4], static_cast<double>(mat1.values[4]));
  EXPECT_EQ(mat2.values[5], static_cast<double>(mat1.values[5]));
  EXPECT_EQ(mat2.values[6], static_cast<double>(mat1.values[6]));
  EXPECT_EQ(mat2.values[7], static_cast<double>(mat1.values[7]));
  EXPECT_EQ(mat2.values[8], static_cast<double>(mat1.values[8])); 
}
TEST(Matrix2, ConvertAssignment2) {
  geom::Matrix2d mat1(1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9);
  geom::Matrix2i mat2;
  mat2 = mat1;
  EXPECT_EQ(mat2.values[0], static_cast<int>(mat1.values[0]));
  EXPECT_EQ(mat2.values[1], static_cast<int>(mat1.values[1]));
  EXPECT_EQ(mat2.values[2], static_cast<int>(mat1.values[2]));
  EXPECT_EQ(mat2.values[3], static_cast<int>(mat1.values[3]));
  EXPECT_EQ(mat2.values[4], static_cast<int>(mat1.values[4]));
  EXPECT_EQ(mat2.values[5], static_cast<int>(mat1.values[5]));
  EXPECT_EQ(mat2.values[6], static_cast<int>(mat1.values[6]));
  EXPECT_EQ(mat2.values[7], static_cast<int>(mat1.values[7]));
  EXPECT_EQ(mat2.values[8], static_cast<int>(mat1.values[8])); 
}
