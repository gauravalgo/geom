
#include <gtest/gtest.h>

#include "geom/Dimensions2.hpp"

TEST(Dimensions2, DefaultConstructor) {
  geom::Dimensions2i d;
  EXPECT_EQ(d.width, 0);
  EXPECT_EQ(d.height, 0);
}
TEST(Dimensions2, ScalarConstructor) {
  geom::Dimensions2i d(1,2);
  EXPECT_EQ(d.width, 1);
  EXPECT_EQ(d.height, 2);
}
TEST(Dimensions2, CopyConstructor) {
  geom::Dimensions2i d1(1,2);
  geom::Dimensions2i d2(d1);
  EXPECT_EQ(d1.width, d2.width);
  EXPECT_EQ(d1.height, d2.height);
}
TEST(Dimensions2, ConvertConstructor1) {
  geom::Dimensions2i d1(1,2);
  geom::Dimensions2d d2(d1);
  EXPECT_EQ(static_cast<double>(d1.width), d2.width);
  EXPECT_EQ(static_cast<double>(d1.height), d2.height);
}
TEST(Dimensions2, ConvertConstructor2) {
  geom::Dimensions2d d1(1.1, 2.2);
  geom::Dimensions2i d2(d1);
  EXPECT_EQ(static_cast<int>(d1.width), d2.width);
  EXPECT_EQ(static_cast<int>(d1.height), d2.height);
}
TEST(Dimensions2, Assignment) {
  geom::Dimensions2i d1(1,2), d2;
  d2 = d1;
  EXPECT_EQ(d1.width, d2.width);
  EXPECT_EQ(d1.height, d2.height);
}
TEST(Dimensions2, ConvertAssignment1) {
  geom::Dimensions2i d1(1,2);
  geom::Dimensions2d d2;
  d2 = d1;
  EXPECT_EQ(static_cast<double>(d1.width), d2.width);
  EXPECT_EQ(static_cast<double>(d1.height), d2.height);
}
TEST(Dimensions2, ConvertAssignment2) {
  geom::Dimensions2d d1(1.1, 2.2);
  geom::Dimensions2i d2;
  d2 = d1;
  EXPECT_EQ(static_cast<int>(d1.width), d2.width);
  EXPECT_EQ(static_cast<int>(d1.width), d2.width);
}

