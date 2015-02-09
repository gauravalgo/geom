
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

#define EXPECT_VEC2_FLOAT_EQ(v1, v2)						\
	do {																					\
		EXPECT_FLOAT_EQ((v1).x, (v2).x);						\
		EXPECT_FLOAT_EQ((v1).y, (v2).y);						\
	}while(0);

#define EXPECT_VEC2_DOUBLE_EQ(v1, v2)						\
	do {																					\
		EXPECT_DOUBLE_EQ((v1).x, (v2).x);						\
		EXPECT_DOUBLE_EQ((v1).y, (v2).y);						\
	}while(0);



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
TEST(Vector2, ConvertConstructor) {
  Vector2<double> v1(1.1, 2.2);
  Vector2<int> v2(v1);
	EXPECT_VEC2(v2, static_cast<int>(v1.x), static_cast<int>(v1.y));
	
	Vector2<int> v3(5, 10);
	Vector2<double> v4(v3);
	EXPECT_VEC2(v4, static_cast<double>(v3.x), static_cast<double>(v3.y));
}
TEST(Vector2, Assignment) {
  Vector2<int> v1(1,2);
  Vector2<int> v2;
  v2 = v1;
	EXPECT_VEC2_EQ(v1, v2);
}
TEST(Vector2, ConvertAssignment) {
  Vector2<double> v1(1.1, 2.2);
  Vector2<int> v2;
  v2 = v1;
	EXPECT_VEC2(v2, static_cast<int>(v1.x), static_cast<int>(v1.y));
	
  Vector2<int> v3(5, 10);
  Vector2<double> v4;
  v4 = v3;
	EXPECT_VEC2(v4, static_cast<double>(v3.x), static_cast<double>(v3.y));
}

TEST(Vector2, Equality) {
	EXPECT_TRUE(Vec2i(1,1) == Vec2i(1,1));
	EXPECT_TRUE(Vec2i(1,2) == Vec2i(1,2));
	EXPECT_TRUE(Vec2i(2,1) == Vec2i(2,1));
	EXPECT_FALSE(Vec2i(1,1) == Vec2i(2,1));
	EXPECT_FALSE(Vec2i(1,1) == Vec2i(1,2));
	EXPECT_FALSE(Vec2i(1,1) == Vec2i(2,2));
}

TEST(Vector2, Inequality) {
	EXPECT_FALSE(Vec2i(1,1) != Vec2i(1,1));
	EXPECT_FALSE(Vec2i(1,2) != Vec2i(1,2));
	EXPECT_FALSE(Vec2i(2,1) != Vec2i(2,1));
	EXPECT_TRUE(Vec2i(1,1) != Vec2i(2,1));
	EXPECT_TRUE(Vec2i(1,1) != Vec2i(1,2));
	EXPECT_TRUE(Vec2i(1,1) != Vec2i(2,2));
}

TEST(Vector2, LessThan) {
	EXPECT_TRUE(Vec2i(1,1) < Vec2i(2,2));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(1,2));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(2,1));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(1,1));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(2,0));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(0,2));
	EXPECT_FALSE(Vec2i(1,1) < Vec2i(0,0));
}

TEST(Vector2, LessEq) {
	EXPECT_TRUE(Vec2i(1,1) <= Vec2i(2,2));
	EXPECT_TRUE(Vec2i(1,1) <= Vec2i(1,2));
	EXPECT_TRUE(Vec2i(1,1) <= Vec2i(2,1));
	EXPECT_TRUE(Vec2i(1,1) <= Vec2i(1,1));
	EXPECT_FALSE(Vec2i(1,1) <= Vec2i(1,0));
	EXPECT_FALSE(Vec2i(1,1) <= Vec2i(0,1));
	EXPECT_FALSE(Vec2i(1,1) <= Vec2i(0,0));
}

TEST(Vector2, GreaterThan) {
	EXPECT_TRUE(Vec2i(1,1) > Vec2i(0,0));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(1,0));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(0,1));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(1,1));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(2,0));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(0,2));
	EXPECT_FALSE(Vec2i(1,1) > Vec2i(2,2));
}

TEST(Vector2, GreaterEq) {
	EXPECT_TRUE(Vec2i(1,1) >= Vec2i(0,0));
	EXPECT_TRUE(Vec2i(1,1) >= Vec2i(1,0));
	EXPECT_TRUE(Vec2i(1,1) >= Vec2i(0,1));
	EXPECT_TRUE(Vec2i(1,1) >= Vec2i(1,1));
	EXPECT_FALSE(Vec2i(1,1) >= Vec2i(2,0));
	EXPECT_FALSE(Vec2i(1,1) >= Vec2i(0,2));
	EXPECT_FALSE(Vec2i(1,1) >= Vec2i(2,2));
}

TEST(Vector2, Negation) {
  Vec2i v1(1,2);
	Vec2i v2 = -v1;
	EXPECT_VEC2(v2, -1, -2);
	
	v1 = Vec2i(-1,2);
	v2 = -v1;
	EXPECT_VEC2(v2, 1, -2);
	
	v1 = Vec2i(1,-2);
	v2 = -v1;
	EXPECT_VEC2(v2, -1,2);
	
	v1 = Vec2i(-1,-2);
	v2 = -v1;
	EXPECT_VEC2(v2, 1,2);
}

TEST(Vector2, Addition) {
  Vec2i v1(1,2);
  Vec2i v2(0,0);
  Vec2i v3(v1 + v2);
	EXPECT_VEC2(v3, 1,2);
	
  v1 = Vec2i(1,2);
  v2 = Vec2i(-1, -2);
  v3 = v1 + v2;
	EXPECT_VEC2(v3, 0, 0);
	
  v1 = Vec2i(1,1);
  v2 = Vec2i(2,3);
  v3 = v1 + v2;
	EXPECT_VEC2(v3, 3, 4);
	
	Vec2i v4(3,2);
	Vec2f v5(2,3);
	auto v6 = v4 + v5;
	::testing::StaticAssertTypeEq<decltype(v6),Vector2<float>>();
	EXPECT_EQ(v6, Vec2f(5,5));
}

TEST(Vector2, AddEq) {
  Vec2i v1(1,2);
  Vec2i v2(2,1);
  v1 += v2;
	EXPECT_VEC2(v1, 3, 3);
	
	Vec2i v3(1,2);
	Vec2f v4(2,3);
	v4 += v3;
	EXPECT_EQ(v4, Vec2f(3.0,5.0));
}

TEST(Vector2, Subtraction) {
	Vec2i v1(2,3);
	Vec2i v2(1,2);
	Vec2i v3 = v1 - v2;
	EXPECT_VEC2(v3, 1, 1);
	
	v1 = Vec2i(2,3);
	v2 = Vec2i(-1,-2);
	v3 = v1 - v2;
	EXPECT_VEC2(v3, 3, 5);
}

TEST(Vector2, SubEq) {
	Vec2i v1(2,3);
	Vec2i v2(1,2);
	v1 -= v2;
	EXPECT_VEC2(v1, 1, 1);
}

TEST(Vector2, Multiplication) {
	Vec2i v1(2,2);
	Vec2i v2(3,4);
	Vec2i v3 = v1 * v2;
	EXPECT_VEC2(v3, 6, 8);
	
	v1 = Vec2i(4, 2);
	v2 = Vec2i(0, -1);
	v3 = v1 * v2;
	EXPECT_VEC2(v3, 0, -2);
	
	Vec2d v4(2.5,2.5);
	Vec2d v5(2.0,2.0);
	Vec2d v6 = v4 * v5;
	EXPECT_VEC2(v6, 5.0, 5.0);
}

TEST(Vector2, MulEq) {
	Vec2i v1(1,2);
	Vec2i v2(2,1);
	v1 *= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Division) {
	Vec2i v1(4, 2);
	Vec2i v2(2, 2);
	Vec2i v3 = v1 / v2;
	EXPECT_VEC2(v3, 2, 1);
	
	v1 = Vec2i(4, 2);
	v2 = Vec2i(-2, 1);
	v3 = v1 / v2;
	EXPECT_VEC2(v3, -2, 2);
}

TEST(Vector2, DivEq) {
	Vec2i v1(10, 6);
	Vec2i v2(5, 3);
	v1 /= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Length) {
	Vec2i v1(0, 10);
	EXPECT_EQ(length(v1), 10.0d);
	
	Vec2i v2(1,10);
	EXPECT_EQ(((double)length(v2)), 10.04987562112089);
}

TEST(Vector2, Dot) {
	Vec2f v1(1.0, 2.0);
	Vec2f v2(2.0, 1.0);
	EXPECT_EQ(dot(v1, v2), 4.0);
	
	v1 = Vec2f(1.5, 1.5);
	v2 = Vec2f(2.0, 4.0);
	EXPECT_EQ(dot(v1, v2), 9.0);
}

TEST(Vector2, Reflect) {
	Vec2f v1 = Vec2f(1.4142135623730951, -1.4142135623730951);
	Vec2f v2(0,1);
	EXPECT_EQ(reflect(v1, v2), Vec2f(1.4142135623730951, 1.4142135623730951));
}

TEST(Vector2, Normalize) {
	Vec2f v1 = Vec2f(1.0, 1.0);
	Vec2f n = normalize(v1);
	Vec2f ref = Vec2f(0.7071067811865475, 0.7071067811865475);
	EXPECT_VEC2_FLOAT_EQ(ref, n);
	
	v1 = Vec2f(1.0, 0.0);
	n = normalize(v1);
	ref = Vec2f(1.0,0.0);
	EXPECT_VEC2_FLOAT_EQ(ref, n);
}

TEST(Vector2, OperatorTypes) {
	Vec2f v1(1.0, 0.0);
	Vec2i v2(2, 1);
	Vec2d v3(3.0, 2.0);
	auto r1 = v1 + v2;
	::testing::StaticAssertTypeEq<decltype(r1),Vector2<float>>();
	
	auto r2 = v2 + v3;
	::testing::StaticAssertTypeEq<decltype(r2),Vector2<double>>();
	
	auto r3 = v1 + v3;
	::testing::StaticAssertTypeEq<decltype(r3),Vector2<double>>();
}

TEST(Vector2, NormalizeType) {
	Vec2f v1(1.0, 1.0);
	auto n1 = normalize(v1);
	::testing::StaticAssertTypeEq<decltype(n1), Vector2<float>>();
	
	Vec2d v2(1.0, 1.0);
	auto n2 = normalize(v2);
	::testing::StaticAssertTypeEq<decltype(n2), Vector2<double>>();
	
	Vec2i v3(1, 1);
	auto n3 = normalize(v3);
	::testing::StaticAssertTypeEq<decltype(n3), Vector2<double>>();
}

TEST(Vector2, LengthType) {
	Vec2f v1(1.0, 1.0);
	auto n1 = length(v1);
	::testing::StaticAssertTypeEq<decltype(n1), float>();
	
	Vec2d v2(1.0, 1.0);
	auto n2 = length(v2);
	::testing::StaticAssertTypeEq<decltype(n2), double>();
	
	Vec2i v3(1, 1);
	auto n3 = length(v3);
	::testing::StaticAssertTypeEq<decltype(n3), double>();
}
