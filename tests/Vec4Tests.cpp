
#include <gtest/gtest.h>

#include "geom/Vector4.hpp"

TEST(Vector4, DefaultConstructor) {
  geom::Vector4<int> v;
  EXPECT_EQ(v.x, 0);
  EXPECT_EQ(v.y, 0);
  EXPECT_EQ(v.z, 0);
  EXPECT_EQ(v.w, 0);
}
TEST(Vector4, ScalarConstructor) {
  geom::Vector4<int> v(1,2,3,4);
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
  EXPECT_EQ(v.z, 3);
  EXPECT_EQ(v.w, 4);
}
TEST(Vector4, CopyConstructor) {
  geom::Vector4<int> v1(1,2,3,4);
  geom::Vector4<int> v2(v1);
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
  EXPECT_EQ(v1.z, v2.z);
  EXPECT_EQ(v1.w, v2.w);
}
TEST(Vector4, ConvertConstructor1) {
  geom::Vector4<double> v1(1.1, 2.2, 3.3, 4.4);
  geom::Vector4<int> v2(v1);
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
  EXPECT_EQ(static_cast<int>(v1.z), v2.z);
  EXPECT_EQ(static_cast<int>(v1.w), v2.w);
}
TEST(Vector4, ConvertConstructor2) {
  geom::Vector4<int> v1(5, 10, 15, 20);
  geom::Vector4<double> v2(v1);
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
  EXPECT_EQ(static_cast<double>(v1.z), v2.z);
  EXPECT_EQ(static_cast<double>(v1.w), v2.w);
}
TEST(Vector4, Assignment) {
  geom::Vector4<int> v1(1,2,3,4);
  geom::Vector4<int> v2;
  v2 = v1;
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
  EXPECT_EQ(v1.z, v2.z);
  EXPECT_EQ(v1.w, v2.w);
}
TEST(Vector4, ConvertAssignment1) {
  geom::Vector4<double> v1(1.1, 2.2, 3.3, 4.4);
  geom::Vector4<int> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
  EXPECT_EQ(static_cast<int>(v1.z), v2.z);
  EXPECT_EQ(static_cast<int>(v1.w), v2.w);
}
TEST(Vector4, ConvertAssignment2) {
  geom::Vector4<int> v1(5, 10, 15, 20);
  geom::Vector4<double> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
  EXPECT_EQ(static_cast<double>(v1.z), v2.z);
  EXPECT_EQ(static_cast<double>(v1.w), v2.w);
}
