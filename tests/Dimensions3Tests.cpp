
#include <gtest/gtest.h>

#include "geom/Dimensions3.hpp"

TEST(Dimensions3, DefaultConstructor) {
  geom::Dimensions3i d;
  EXPECT_EQ(d.width, 0);
  EXPECT_EQ(d.height, 0);
  EXPECT_EQ(d.depth, 0);
}
TEST(Dimensions3, ScalarConstructor) {
  geom::Dimensions3i d(1,2,3);
  EXPECT_EQ(d.width, 1);
  EXPECT_EQ(d.height, 2);
  EXPECT_EQ(d.depth, 3);
}
TEST(Dimensions3, CopyConstructor) {
  geom::Dimensions3i d1(1,2,3);
  geom::Dimensions3i d2(d1);
  EXPECT_EQ(d1.width, d2.width);
  EXPECT_EQ(d1.height, d2.height);
  EXPECT_EQ(d1.depth, d2.depth);
}
TEST(Dimensions3, ConvertConstructor1) {
  geom::Dimensions3i d1(1,2,3);
  geom::Dimensions3d d2(d1);
  EXPECT_EQ(static_cast<double>(d1.width), d2.width);
  EXPECT_EQ(static_cast<double>(d1.height), d2.height);
  EXPECT_EQ(static_cast<double>(d1.depth), d2.depth);
}
TEST(Dimensions3, ConvertConstructor2) {
  geom::Dimensions3d d1(1.1, 2.2, 3.3);
  geom::Dimensions3i d2(d1);
  EXPECT_EQ(static_cast<int>(d1.width), d2.width);
  EXPECT_EQ(static_cast<int>(d1.height), d2.height);
  EXPECT_EQ(static_cast<int>(d1.depth), d2.depth);
}
TEST(Dimensions3, Assignment) {
  geom::Dimensions3i d1(1,2,3), d2;
  d2 = d1;
  EXPECT_EQ(d1.width, d2.width);
  EXPECT_EQ(d1.height, d2.height);
  EXPECT_EQ(d1.depth, d2.depth);
}
TEST(Dimensions3, ConvertAssignment1) {
  geom::Dimensions3i d1(1,2,3);
  geom::Dimensions3d d2;
  d2 = d1;
  EXPECT_EQ(static_cast<double>(d1.width), d2.width);
  EXPECT_EQ(static_cast<double>(d1.height), d2.height);
  EXPECT_EQ(static_cast<double>(d1.depth), d2.depth);
}
TEST(Dimensions3, ConvertAssignment2) {
  geom::Dimensions3d d1(1.1, 2.2, 3.3);
  geom::Dimensions3i d2;
  d2 = d1;
  EXPECT_EQ(static_cast<int>(d1.width), d2.width);
  EXPECT_EQ(static_cast<int>(d1.height), d2.height);
  EXPECT_EQ(static_cast<int>(d1.depth), d2.depth);
}

