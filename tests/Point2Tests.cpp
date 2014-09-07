
#include "gtest/gtest.h"

#include "geom/Point2.hpp"

TEST(Point2, DefaultConstructor) {
  geom::Point2i p;
  EXPECT_EQ(p.x, 0);
  EXPECT_EQ(p.y, 0);
}
TEST(Point2, ScalarConstructor) {
  geom::Point2i p(1,2);
  EXPECT_EQ(p.x, 1);
  EXPECT_EQ(p.y, 2);
}
TEST(Point2, CopyConstructor) {
  geom::Point2i p1(1,2);
  geom::Point2i p2(p1);
  EXPECT_EQ(p1.x, p2.x);
  EXPECT_EQ(p1.y, p2.y);
}
TEST(Point2, ConvertConstructor1) {
  geom::Point2i p1(1,2);
  geom::Point2d p2(p1);
  EXPECT_EQ(static_cast<double>(p1.x), p2.x);
  EXPECT_EQ(static_cast<double>(p1.y), p2.y);
}
TEST(Point2, ConvertConstructor2) {
  geom::Point2d p1(1.1, 2.2);
  geom::Point2i p2(p1);
  EXPECT_EQ(static_cast<int>(p1.x), p2.x);
  EXPECT_EQ(static_cast<int>(p1.y), p2.y);
}
TEST(Point2, Assignment) {
  geom::Point2i p1(1, 2);
  geom::Point2i p2;
  p2 = p1;
  EXPECT_EQ(p1.x, p2.x);
  EXPECT_EQ(p1.y, p2.y);
}
TEST(Point2, ConvertAssignment1) {
  geom::Point2i p1(1, 2);
  geom::Point2d p2;
  p2 = p1;
  EXPECT_EQ(static_cast<double>(p1.x), p2.x);
  EXPECT_EQ(static_cast<double>(p1.y), p2.y);
}
TEST(Point2, ConvertAssignment2) {
  geom::Point2d p1(1.1, 2.2);
  geom::Point2i p2;
  p2 = p1;
  EXPECT_EQ(static_cast<int>(p1.x), p2.x);
  EXPECT_EQ(static_cast<int>(p1.y), p2.y);
}
