
#include <gtest/gtest.h>

#include "geom/Vector3.hpp"

using namespace geom;

TEST(Vector3, DefaultConstructor) {
  Vector3<int> v;
  EXPECT_EQ(v.x, 0);
  EXPECT_EQ(v.y, 0);
  EXPECT_EQ(v.z, 0);
}
TEST(Vector3, ScalarConstructor) {
  Vector3<int> v(1,2,3);
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
  EXPECT_EQ(v.z, 3);
}
TEST(Vector3, CopyConstructor) {
  Vector3<int> v1(1,2,3);
  Vector3<int> v2(v1);
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
  EXPECT_EQ(v1.z, v2.z);
}
TEST(Vector3, ConvertConstructor) {
  Vector3<double> v1(1.1, 2.2, 3.8);
  Vector3<int> v2(v1);
	EXPECT_EQ(v2, Vector3<int>(1,2,3));
	
  Vector3<int> v3(5, 10, 15);
  Vector3<double> v4(v3);
	EXPECT_EQ(v4, Vector3<double>(5.0, 10.0, 15.0));
}

TEST(Vector3, Assignment) {
  Vector3<int> v1(1,2,3);
  Vector3<int> v2;
  v2 = v1;
	EXPECT_EQ(v2, v1);
}
TEST(Vector3, ConvertAssignment) {
  Vector3<double> v1(1.1, 2.2, 3.8);
  Vector3<int> v2;
  v2 = v1;
	EXPECT_EQ(v2, Vector3<int>(1,2,3));
	
	v2 = Vec3i(5, 10, 15);
	v1 = v2;
	EXPECT_EQ(v1, Vector3<double>(5,10,15));
}

TEST(Vector3, Equality) {
	EXPECT_TRUE(Vec3i(1,1,1) == Vec3i(1,1,1));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(1,1,0));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(1,0,1));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(0,1,1));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(1,0,0));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(0,1,0));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(0,0,1));
	EXPECT_FALSE(Vec3i(1,1,1) == Vec3i(0,0,0));
}

TEST(Vector3, Inequality) {
	EXPECT_FALSE(Vec3i(1,1,1) != Vec3i(1,1,1));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(1,1,0));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(1,0,1));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(0,1,1));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(1,0,0));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(0,1,0));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(0,0,1));
	EXPECT_TRUE(Vec3i(1,1,1) != Vec3i(0,0,0));
}

TEST(Vector3, LessThan) {
	EXPECT_TRUE(Vec3i(1,1,1) < Vec3i(2,2,2));
	EXPECT_FALSE(Vec3i(1,1,1) < Vec3i(2,2,1));
	EXPECT_FALSE(Vec3i(1,1,1) < Vec3i(2,1,2));
	EXPECT_FALSE(Vec3i(1,1,1) < Vec3i(1,2,2));
	EXPECT_FALSE(Vec3i(1,1,1) < Vec3i(1,1,1));
	EXPECT_FALSE(Vec3i(1,1,1) < Vec3i(0,0,0));
}

TEST(Vector3, LessEqual) {
	EXPECT_TRUE(Vec3i(1,1,1) <= Vec3i(2,2,2));
	EXPECT_TRUE(Vec3i(1,1,1) <= Vec3i(2,2,1));
	EXPECT_TRUE(Vec3i(1,1,1) <= Vec3i(2,1,2));
	EXPECT_TRUE(Vec3i(1,1,1) <= Vec3i(1,2,2));
	EXPECT_TRUE(Vec3i(1,1,1) <= Vec3i(1,1,1));
	EXPECT_FALSE(Vec3i(1,1,1) <= Vec3i(0,0,0));
}

TEST(Vector3, GreaterThan) {
	EXPECT_FALSE(Vec3i(1,1,1) > Vec3i(2,2,2));
	EXPECT_FALSE(Vec3i(1,1,1) > Vec3i(2,2,1));
	EXPECT_FALSE(Vec3i(1,1,1) > Vec3i(2,1,2));
	EXPECT_FALSE(Vec3i(1,1,1) > Vec3i(1,2,2));
	EXPECT_FALSE(Vec3i(1,1,1) > Vec3i(1,1,1));
	EXPECT_TRUE(Vec3i(1,1,1) > Vec3i(0,0,0));
}

TEST(Vector3, GreaterEqual) {
	EXPECT_FALSE(Vec3i(1,1,1) >= Vec3i(2,2,2));
	EXPECT_FALSE(Vec3i(1,1,1) >= Vec3i(2,2,1));
	EXPECT_FALSE(Vec3i(1,1,1) >= Vec3i(2,1,2));
	EXPECT_FALSE(Vec3i(1,1,1) >= Vec3i(1,2,2));
	EXPECT_TRUE(Vec3i(1,1,1) >= Vec3i(1,1,1));
	EXPECT_TRUE(Vec3i(1,1,1) >= Vec3i(0,0,0));
}

TEST(Vector3, Addition) {
	EXPECT_EQ(Vec3i(1,2,3) + Vec3i(0,0,0), Vec3i(1,2,3));
	EXPECT_EQ(Vec3i(1,2,3) + Vec3i(-1,-2,-3), Vec3i(0,0,0));
	EXPECT_EQ(Vec3i(1,2,3) + Vec3i(1,-1,0), Vec3i(2,1,3));
	EXPECT_EQ(Vec3i(1,1,1) + Vec3i(2,3,4), Vec3i(3,4,5));
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)+Vec3f(1,1,1)),
																Vector3<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)+Vec3d(1,1,1)),
																Vector3<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec3f(1,1,1)+Vec3d(1,1,1)),
																Vector3<double>>();
}

TEST(Vector3, AdditionAssignment) {
  Vec3i v1(1,2,4);
  Vec3i v2(2,1,-1);
  v1 += v2;
	EXPECT_EQ(v1, Vec3i(3,3,3));
}

TEST(Vector3, Subtraction) {
	EXPECT_EQ(Vec3i(1,2,3) - Vec3i(0,0,0), Vec3i(1,2,3));
	EXPECT_EQ(Vec3i(1,2,3) - Vec3i(-1,-2,-3), Vec3i(2,4,6));
	EXPECT_EQ(Vec3i(1,2,3) - Vec3i(-1,1,0), Vec3i(2,1,3));
	EXPECT_EQ(Vec3i(1,1,1) - Vec3i(2,3,4), Vec3i(-1, -2, -3));
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)-Vec3f(1,1,1)),
																Vector3<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)-Vec3d(1,1,1)),
																Vector3<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec3f(1,1,1)-Vec3d(1,1,1)),
																Vector3<double>>();
}

TEST(Vector3, SubtractionAssignment) {
	Vec3i v1(1,2,3);
	Vec3i v2(2,1,-1);
	v1 -= v2;
	EXPECT_EQ(v1, Vec3i(-1,1,4));
}

TEST(Vector3, Multiplication) {
	EXPECT_EQ(Vec3i(1,2,3) * Vec3i(0,0,0), Vec3i(0,0,0));
	EXPECT_EQ(Vec3i(1,2,3) * Vec3i(1,1,1), Vec3i(1,2,3));
	EXPECT_EQ(Vec3i(1,2,3) * Vec3i(-1,-1,-1), Vec3i(-1,-2,-3));
	EXPECT_EQ(Vec3i(1,2,3) * Vec3i(2,2,2), Vec3i(2,4,6));
	EXPECT_EQ(Vec3d(1,2,3) * Vec3d(0.5,0.5,0.5), Vec3d(0.5, 1.0, 1.5));
	EXPECT_EQ(Vec3i(1,1,1) * 2, Vec3i(2,2,2));
	EXPECT_EQ(2 * Vec3i(1,1,1), Vec3i(2,2,2));
	EXPECT_EQ(Vec3i(1,1,1) * 0.5, Vec3d(0.5,0.5,0.5));
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)*Vec3f(1,1,1)),
																Vector3<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)*Vec3d(1,1,1)),
																Vector3<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec3f(1,1,1)*Vec3d(1,1,1)),
																Vector3<double>>();
}

TEST(Vector3, MutliplicationAssignment) {
	Vec3i v1(1,2,3);
	Vec3i v2(-1,2,0);
	v1 *= v2;
	EXPECT_EQ(v1, Vec3i(-1,4,0));
}

TEST(Vector3, Division) {
	EXPECT_EQ(Vec3i(2,4,6) / Vec3i(2,2,2), Vec3i(1,2,3));
	EXPECT_EQ(Vec3i(2,4,6) / Vec3i(1,1,1), Vec3i(2,4,6));
	EXPECT_EQ(Vec3i(2,4,6) / Vec3i(-1,-1,-1), Vec3i(-2,-4,-6));
	EXPECT_EQ(Vec3i(2,4,6) / Vec3i(2,4,6), Vec3i(1,1,1));
	EXPECT_EQ(Vec3d(1,1,1) / Vec3d(2,3,4), Vec3d(0.5,1.0/3.0,0.25));
	EXPECT_EQ(Vec3d(1,2,3) / Vec3d(0.5, 0.25, 0.125), Vec3d(2,8,24));
	EXPECT_EQ(Vec3d(2,3,4) / 2.0, Vec3d(1,1.5,2));
	EXPECT_EQ(Vec3d(2,3,4) / 0.5, Vec3d(4,6,8));
	EXPECT_EQ(Vec3d(2,3,4) / -0.5, Vec3d(-4,-6,-8));
	
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)/Vec3f(1,1,1)),
																Vector3<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec3i(1,1,1)/Vec3d(1,1,1)),
																Vector3<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec3f(1,1,1)/Vec3d(1,1,1)),
																Vector3<double>>();
}

TEST(Vector3, DivisionAssignment) {
	Vec3i v1(2,3,4);
	Vec3i v2(2,2,2);
	v1 /= v2;
	EXPECT_EQ(v1, Vec3i(1,1,2));
}

TEST(Vector3, Length) {
	EXPECT_EQ(length(Vec3i(1,0,0)), 1.0);
	EXPECT_EQ(length(Vec3i(0,1,0)), 1.0);
	EXPECT_EQ(length(Vec3i(0,0,1)), 1.0);
	EXPECT_FLOAT_EQ(length(Vec3f(1,1,1)), 1.7320508075688772);
	EXPECT_FLOAT_EQ(length(Vec3f(2,2,2)), 3.4641016151377544);
	EXPECT_FLOAT_EQ(length(Vec3f(1,-1,1)),1.7320508075688772);
	EXPECT_FLOAT_EQ(length(Vec3f(-2,2,2)),3.4641016151377544);
}

TEST(Vector3, Dot) {
	EXPECT_EQ(dot(Vec3i(1,0,0), Vec3i(0,1,1)),0);
	EXPECT_EQ(dot(Vec3i(1,1,1), Vec3i(2,3,4)),9);
	EXPECT_EQ(dot(Vec3i(-1,-1,-1), Vec3i(2,2,2)), -6);
	EXPECT_FLOAT_EQ(dot(Vec3f(1,1,1),Vec3f(0.5,0.5,0.5)),1.5);
}

TEST(Vector3, Reflect) {
	EXPECT_EQ(reflect(Vec3d(1,-1,1),Vec3d(0,1,0)),Vec3d(1,1,1));
	EXPECT_EQ(reflect(Vec3d(1,0.1,1), Vec3d(0,-1,0)), Vec3d(1,-0.1,1));
	
	Vec3d v(0.1, 1, 3.2);
	Vec3d n(0.7071067811865475, 0, -0.7071067811865475);
	Vec3d r = reflect(v, n);
	EXPECT_FLOAT_EQ(3.2, r.x);
	EXPECT_FLOAT_EQ(1, r.y);
	EXPECT_FLOAT_EQ(0.1, r.z);
}

#define SQRT3 0.5773502691896258
TEST(Vector3, Normalize) {
	EXPECT_EQ(normalize(Vec3f(1,0,0)), Vec3f(1,0,0));
	EXPECT_EQ(normalize(Vec3f(0,1,0)), Vec3f(0,1,0));
	EXPECT_EQ(normalize(Vec3f(0,0,1)), Vec3f(0,0,1));
	EXPECT_EQ(normalize(Vec3f(1,1,1)), Vec3f(SQRT3,SQRT3,SQRT3));
}
