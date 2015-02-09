
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
	EXPECT_EQ(Vec2i(1,2) + Vec2i(0,0), Vec2i(1,2));
	EXPECT_EQ(Vec2i(1,2) + Vec2i(-1,-2), Vec2i(0,0));
	EXPECT_EQ(Vec2i(1,1) + Vec2i(2,3), Vec2i(3,4));
	EXPECT_EQ(Vec2i(2,3) + Vec2f(3,2), Vec2f(5,5));
	::testing::StaticAssertTypeEq<decltype(Vec2i()+Vec2f()),Vector2<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec2i()+Vec2d()),Vector2<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec2f()+Vec2d()),Vector2<double>>();
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
	EXPECT_EQ(Vec2i(2,3) - Vec2i(1,2), Vec2i(1,1));
	EXPECT_EQ(Vec2i(2,3) - Vec2i(-1,-2), Vec2i(3,5));
	EXPECT_EQ(Vec2i(2,3) - Vec2i(0,0), Vec2i(2,3));
	::testing::StaticAssertTypeEq<decltype(Vec2i()-Vec2f()),Vector2<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec2i()-Vec2d()),Vector2<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec2f()-Vec2d()),Vector2<double>>();
}

TEST(Vector2, SubEq) {
	Vec2i v1(2,3);
	Vec2i v2(1,2);
	v1 -= v2;
	EXPECT_VEC2(v1, 1, 1);
}

TEST(Vector2, Multiplication) {
	EXPECT_EQ(Vec2i(2,2) * Vec2i(0,0), Vec2i(0,0));
	EXPECT_EQ(Vec2i(2,3) * Vec2i(1,1), Vec2i(2,3));
	EXPECT_EQ(Vec2i(3,2) * Vec2i(-1,0), Vec2i(-3,0));
	EXPECT_EQ(Vec2i(2,2) * Vec2i(3,4), Vec2i(6,8));
	EXPECT_EQ(Vec2i(4,2) * Vec2i(0,-1), Vec2i(0,-2));
	EXPECT_EQ(Vec2d(2.5,2.5) * Vec2d(2.0,2.0), Vec2d(5.0,5.0));
	::testing::StaticAssertTypeEq<decltype(Vec2i()*Vec2f()),Vector2<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec2i()*Vec2d()),Vector2<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec2f()*Vec2d()),Vector2<double>>();
}

TEST(Vector2, MulEq) {
	Vec2i v1(1,2);
	Vec2i v2(2,1);
	v1 *= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Division) {
	EXPECT_EQ(Vec2i(4,2) / Vec2i(2,2), Vec2i(2,1));
	EXPECT_EQ(Vec2i(4,2) / Vec2i(-2,1), Vec2i(-2,2));
	EXPECT_EQ(Vec2i(4,2) / Vec2i(1,1), Vec2i(4,2));
	EXPECT_EQ(Vec2d(4,2) / Vec2d(0.5,0.5), Vec2d(8,4));
	EXPECT_EQ(Vec2d(4,3) / Vec2d(-0.1,2.0), Vec2d(-40,1.5));
	::testing::StaticAssertTypeEq<decltype(Vec2i()/Vec2f()),Vector2<float>>();
	::testing::StaticAssertTypeEq<decltype(Vec2i()/Vec2d()),Vector2<double>>();
	::testing::StaticAssertTypeEq<decltype(Vec2f()/Vec2d()),Vector2<double>>();
}

TEST(Vector2, DivEq) {
	Vec2i v1(10, 6);
	Vec2i v2(5, 3);
	v1 /= v2;
	EXPECT_VEC2(v1, 2, 2);
}

TEST(Vector2, Length) {
	EXPECT_EQ(length(Vec2i(0,10)), 10.0);
	EXPECT_EQ(length(Vec2i(1,10)), 10.04987562112089);
	EXPECT_EQ(length(Vec2i(2,2)), 2.8284271247461903);
	::testing::StaticAssertTypeEq<decltype(length(Vec2i())),double>();
	::testing::StaticAssertTypeEq<decltype(length(Vec2f())),float>();
	::testing::StaticAssertTypeEq<decltype(length(Vec2d())),double>();
}

TEST(Vector2, Dot) {
	EXPECT_EQ(dot(Vec2f(1,2),Vec2f(2,1)),4.0f);
	EXPECT_EQ(dot(Vec2f(1.5,1.5),Vec2f(2.0,4.0)),9.0f);
	EXPECT_EQ(dot(Vec2f(0,0),Vec2f(10,10)),0.0f);
	::testing::StaticAssertTypeEq<decltype(dot(Vec2i(),Vec2f())),float>();
	::testing::StaticAssertTypeEq<decltype(dot(Vec2i(),Vec2d())),double>();
	::testing::StaticAssertTypeEq<decltype(dot(Vec2f(),Vec2d())),double>();
}

TEST(Vector2, Reflect) {
	EXPECT_EQ(reflect(Vec2f(1.4142135623730951, -1.4142135623730951),
										Vec2f(0,1)),
						Vec2f(1.4142135623730951, 1.4142135623730951));
}

TEST(Vector2, Normalize) {
	EXPECT_EQ(normalize(Vec2f(1.0,1.0)),
						Vec2f(0.7071067811865475, 0.7071067811865475));
	EXPECT_FLOAT_EQ(length(normalize(Vec2f(1.0,1.0))), 1.0);
	EXPECT_EQ(normalize(Vec2f(1,0)),Vec2f(1,0));
}
