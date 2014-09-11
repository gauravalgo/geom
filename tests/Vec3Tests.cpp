
#include <gtest/gtest.h>

#include "geom/Vector3.hpp"

TEST(Vector3, DefaultConstructor) {
  geom::Vector3<int> v;
  EXPECT_EQ(v.x, 0);
  EXPECT_EQ(v.y, 0);
  EXPECT_EQ(v.z, 0);
}
TEST(Vector3, ScalarConstructor) {
  geom::Vector3<int> v(1,2,3);
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
  EXPECT_EQ(v.z, 3);
}
TEST(Vector3, CopyConstructor) {
  geom::Vector3<int> v1(1,2,3);
  geom::Vector3<int> v2(v1);
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
  EXPECT_EQ(v1.z, v2.z);
}
TEST(Vector3, ConvertConstructor1) {
  geom::Vector3<double> v1(1.1, 2.2, 3.3);
  geom::Vector3<int> v2(v1);
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
  EXPECT_EQ(static_cast<int>(v1.z), v2.z);
}
TEST(Vector3, ConvertConstructor2) {
  geom::Vector3<int> v1(5, 10, 15);
  geom::Vector3<double> v2(v1);
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
  EXPECT_EQ(static_cast<double>(v1.z), v2.z);
}
TEST(Vector3, Assignment) {
  geom::Vector3<int> v1(1,2,3);
  geom::Vector3<int> v2;
  v2 = v1;
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
  EXPECT_EQ(v1.z, v2.z);
}
TEST(Vector3, ConvertAssignment1) {
  geom::Vector3<double> v1(1.1, 2.2, 3.3);
  geom::Vector3<int> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
  EXPECT_EQ(static_cast<int>(v1.z), v2.z);
}
TEST(Vector3, ConvertAssignment2) {
  geom::Vector3<int> v1(5, 10, 15);
  geom::Vector3<double> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
  EXPECT_EQ(static_cast<double>(v1.z), v2.z);
}

TEST(Vector3, Addition1) {
  geom::Vec3i v1(1,2,3);
  geom::Vec3i v2(0,0,0);
  geom::Vec3i v3(v1 + v2);
  EXPECT_EQ(v3.x, 1);
  EXPECT_EQ(v3.y, 2);
  EXPECT_EQ(v3.z, 3);
}

TEST(Vector3, Addition2) {
  geom::Vec3i v1(1,2,3);
  geom::Vec3i v2(-1, -2, -3);
  geom::Vec3i v3(v1 + v2);
  EXPECT_EQ(v3.x, 0);
  EXPECT_EQ(v3.y, 0);
  EXPECT_EQ(v3.z, 0);
}

TEST(Vector3, Addition3) {
  geom::Vec3i v1(1,1,1);
  geom::Vec3i v2(2,3,4);
  geom::Vec3i v3(v1 + v2);
  EXPECT_EQ(v3.x, 3);
  EXPECT_EQ(v3.y, 4);
  EXPECT_EQ(v3.z, 5);
}

TEST(Vector3, AdditionAssignment) {
  geom::Vec3i v1(1,2,4);
  geom::Vec3i v2(2,1,-1);
  v1 += v2;
  EXPECT_EQ(v1.x, 3);
  EXPECT_EQ(v1.y, 3);
  EXPECT_EQ(v1.z, 3);
}
