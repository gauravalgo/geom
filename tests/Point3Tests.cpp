
#include "gtest/gtest.h"

#include "geom/Point3.hpp"

TEST(Point3, DefaultConstructor) {
  geom::Point3i p;
  EXPECT_EQ(p.x, 0);
  EXPECT_EQ(p.y, 0);
  EXPECT_EQ(p.z, 0);
}
TEST(Point3, ScalarConstructor) {
  geom::Point3i p(1,2,3);
  EXPECT_EQ(p.x, 1);
  EXPECT_EQ(p.y, 2);
  EXPECT_EQ(p.z, 3);
}
TEST(Point3, CopyConstructor) {
  geom::Point3i p1(1,2,3);
  geom::Point3i p2(p1);
  EXPECT_EQ(p1.x, p2.x);
  EXPECT_EQ(p1.y, p2.y);
  EXPECT_EQ(p1.z, p2.z);
}
TEST(Point3, ConvertConstructor1) {
  geom::Point3i p1(1,2,3);
  geom::Point3d p2(p1);
  EXPECT_EQ(static_cast<double>(p1.x), p2.x);
  EXPECT_EQ(static_cast<double>(p1.y), p2.y);
  EXPECT_EQ(static_cast<double>(p1.z), p2.z);
}
TEST(Point3, ConvertConstructor2) {
  geom::Point3d p1(1.1, 2.2, 3.3);
  geom::Point3i p2(p1);
  EXPECT_EQ(static_cast<int>(p1.x), p2.x);
  EXPECT_EQ(static_cast<int>(p1.y), p2.y);
  EXPECT_EQ(static_cast<int>(p1.z), p2.z);
}
TEST(Point3, Assignment) {
  geom::Point3i p1(1, 2, 3);
  geom::Point3i p2;
  p2 = p1;
  EXPECT_EQ(p1.x, p2.x);
  EXPECT_EQ(p1.y, p2.y);
  EXPECT_EQ(p1.z, p2.z);
}
TEST(Point3, ConvertAssignment1) {
  geom::Point3i p1(1, 2, 3);
  geom::Point3d p2;
  p2 = p1;
  EXPECT_EQ(static_cast<double>(p1.x), p2.x);
  EXPECT_EQ(static_cast<double>(p1.y), p2.y);
  EXPECT_EQ(static_cast<double>(p1.z), p2.z);
}
TEST(Point3, ConvertAssignment2) {
  geom::Point3d p1(1.1, 2.2, 3.3);
  geom::Point3i p2;
  p2 = p1;
  EXPECT_EQ(static_cast<int>(p1.x), p2.x);
  EXPECT_EQ(static_cast<int>(p1.y), p2.y);
  EXPECT_EQ(static_cast<int>(p1.z), p2.z);
}
