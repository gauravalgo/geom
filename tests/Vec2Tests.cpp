
#include <iostream>
#include <gtest/gtest.h>

#include "geom/Vector2.hpp"
#include "TypeStrings.hpp"

namespace geom {
	template <typename Scalar>
	void PrintTo(const Vector2<Scalar> & v, ::std::ostream* os) {
		*os << "Vec2<" << TypeString<Scalar>() << ">(" << v.x << ", " << v.y << ")";
	}
}

using namespace geom;

#define EXPECT_VEC2(v1, x2, y2) \
	do {												 \
		EXPECT_EQ((v1).x, x2);		 \
		EXPECT_EQ((v1).y, y2);		 \
	}while(0)
#define EXPECT_VEC2_EQ(v1, v2) \
	do {												 \
		EXPECT_EQ((v1).x, (v2).x); \
		EXPECT_EQ((v1).y, (v2).y); \
	}while(0)

TEST(Vector2, DefaultConstructor) {
  Vector2<int> v;
	EXPECT_VEC2(v,0,0);
}

TEST(Vector2, ScalarConstructor) {
  Vector2<int> v(1,2);
	EXPECT_VEC2(v, 1,2);
}

TEST(Vector2, CopyConstructor) {
  Vector2<int> v1(1,2);
  Vector2<int> v2(v1);
	EXPECT_VEC2_EQ(v1,v2);
}
TEST(Vector2, ConvertConstructor1) {
  Vector2<double> v1(1.1, 2.2);
  Vector2<int> v2(v1);
	EXPECT_VEC2(v2, static_cast<int>(v1.x), static_cast<int>(v1.y));
}
TEST(Vector2, ConvertConstructor2) {
  Vector2<int> v1(5, 10);
  Vector2<double> v2(v1);
	EXPECT_VEC2(v2, static_cast<double>(v1.x), static_cast<double>(v1.y));
}
TEST(Vector2, Assignment) {
  Vector2<int> v1(1,2);
  Vector2<int> v2;
  v2 = v1;
	EXPECT_VEC2_EQ(v1, v2);
}
TEST(Vector2, ConvertAssignment1) {
  Vector2<double> v1(1.1, 2.2);
  Vector2<int> v2;
  v2 = v1;
	EXPECT_VEC2(v2, static_cast<int>(v1.x), static_cast<int>(v1.y));
}
TEST(Vector2, ConvertAssignment2) {
  Vector2<int> v1(5, 10);
  Vector2<double> v2;
  v2 = v1;
	EXPECT_VEC2(v2, static_cast<double>(v1.x), static_cast<double>(v1.y));
}

TEST(Vector2, Negation1) {
  Vec2i v1(1,2);
	Vec2i v2 = -v1;
	EXPECT_VEC2(v2, -1, -2);
}

TEST(Vector2, Negation2) {
	Vec2i v1(-1,2);
	Vec2i v2 = -v1;
	EXPECT_VEC2(v2, 1, -2);
}

TEST(Vector2, Negation3) {
	Vec2i v1(1,-2);
	Vec2i v2 = -v1;
	EXPECT_VEC2(v2, -1,2);
}
TEST(Vector2, Negation4) {
	Vec2i v1(-1,-2);
	Vec2i v2 = -v1;
	EXPECT_VEC2(v2, 1,2);
}

TEST(Vector2, Addition1) {
  Vec2i v1(1,2);
  Vec2i v2(0,0);
  Vec2i v3(v1 + v2);
	EXPECT_VEC2(v3, 1,2);
}

TEST(Vector2, Addition2) {
  Vec2i v1(1,2);
  Vec2i v2(-1, -2);
  Vec2i v3(v1 + v2);
	EXPECT_VEC2(v3, 0, 0);
}

TEST(Vector2, Addition3) {
  Vec2i v1(1,1);
  Vec2i v2(2,3);
  Vec2i v3(v1 + v2);
	EXPECT_VEC2(v3, 3, 4);
}

TEST(Vector2, Addition_DifferentTypes) {
	Vec2i v1(3,2);
	Vec2f v2(2,3);
	Vec2i v3 = v1 + v2;
	EXPECT_VEC2(v3, 5, 5);
}

TEST(Vector2, AddEq) {
  Vec2i v1(1,2);
  Vec2i v2(2,1);
  v1 += v2;
	EXPECT_VEC2(v1, 3, 3);
}

TEST(Vector2, AddEq_DifferentTypes) {
	Vec2i v1(1,2);
	Vec2f v2(2,3);
	v1 += v2;
	EXPECT_VEC2(v1, 3, 5);
}

TEST(Vector2, Subtraction1) {
	Vec2i v1(2,3);
	Vec2i v2(1,2);
	Vec2i v3 = v1 - v2;
	EXPECT_VEC2(v3, 1, 1);
}

TEST(Vector2, Subtraction2) {
	Vec2i v1(2,3);
	Vec2i v2(-1,-2);
	Vec2i v3 = v1 - v2;
	EXPECT_VEC2(v3, 3, 5);
}

TEST(Vector2, SubEq) {
	Vec2i v1(2,3);
	Vec2i v2(1,2);
	v1 -= v2;
	EXPECT_VEC2(v1, 1, 1);
}

TEST(Vector2, Multiplication1) {
	Vec2i v1(2,2);
	Vec2i v2(3,4);
	Vec2i v3 = v1 * v2;
	EXPECT_VEC2(v3, 6, 8);
}

TEST(Vector2, Multiplication2) {
	Vec2d v1(2.5,2.5);
	Vec2d v2(2.0,2.0);
	Vec2d v3 = v1 * v2;
	EXPECT_VEC2(v3, 5.0, 5.0);
}
TEST(Vector2, Multiplication3) {
	Vec2i v1(4, 2);
	Vec2i v2(0, -1);
	Vec2i v3 = v1 * v2;
	EXPECT_VEC2(v3, 0, -2);
}

TEST(Vector2, MulEq) {
	Vec2i v1(1,2);
	Vec2i v2(2,1);
	v1 *= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Division1) {
	Vec2i v1(4, 2);
	Vec2i v2(2, 2);
	Vec2i v3 = v1 / v2;
	EXPECT_VEC2(v3, 2, 1);
}

TEST(Vector2, Division2) {
	Vec2i v1(4, 2);
	Vec2i v2(-2, 1);
	Vec2i v3 = v1 / v2;
	EXPECT_VEC2(v3, -2, 2);
}

TEST(Vector2, DivEq) {
	Vec2i v1(10, 6);
	Vec2i v2(5, 3);
	v1 /= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Length1) {
	Vec2i v1(0, 10);
	EXPECT_EQ(length(v1), 10.0d);
}

TEST(Vector2, Length2) {
	Vec2i v2(1,10);
	EXPECT_EQ(((double)length(v2)), 10.04987562112089);
}

TEST(Vector2, Dot1) {
	Vec2f v1(1.0, 2.0);
	Vec2f v2(2.0, 1.0);
	EXPECT_EQ(dot(v1, v2), 4.0);
}

TEST(Vector2, Dot2) {
	Vec2f v1(1.5, 1.5);
	Vec2f v2(2.0, 4.0);
	EXPECT_EQ(dot(v1, v2), 9.0);
}

TEST(Vector2, Reflect1) {
	Vec2f v1 = Vec2f(1.4142135623730951, -1.4142135623730951);
	Vec2f v2(0,1);
	EXPECT_EQ(reflect(v1, v2), Vec2f(1.4142135623730951, 1.4142135623730951));
}

TEST(Vector2, Normalize1) {
	Vec2f v1 = Vec2f(1.0, 1.0);
	EXPECT_EQ(normalize(v1), Vec2f(0.7071067811865475, 0.7071067811865475));
}
