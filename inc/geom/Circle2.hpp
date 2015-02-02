
/**
 * \File Circle2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Line2 structure
 */

/* Copyright (C) 2014 Troy Varney
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef GEOM_CIRCLE_2_HPP
#define GEOM_CIRCLE_2_HPP

#include <cstdint>
#include "Point2.hpp"

namespace geom {
	template <typename Scalar>
	struct Circle2 {
		constexpr Circle2() :
			center(Scalar(0), Scalar(0)), radius(Scalar(1))
		{ }
		constexpr Circle2(const Point2<Scalar> &center, const Scalar &radius) :
			center(center), radius(radius)
		{ }
		constexpr Circle2(const Circle2<Scalar> &source) :
			center(source.center), radius(source.radius)
		{ }
		template <typename Other>
		constexpr Circle2(const Circle2<Other> &source) :
			center(source.center), radius(source.radius)
		{ }
		
		Circle2<Scalar> & operator=(const Circle2<Scalar> &source) {
			center = source.center;
			radius = source.radius;
			return *this;
		}
		template <typename Other>
		Circle2<Scalar> & operator=(const Circle2<Other> &source) {
			center = source.center;
			radius = source.radius;
			return *this;
		}
		
		Point2<Scalar> center;
		Scalar radius;
	};
	
	typedef Circle2<double> Circle2d;
	typedef Circle2<float> Circle2f;
	typedef Circle2<uint32_t> Circle2u;
	typedef Circle2<int32_t> Circle2i;
	typedef Circle2<uint64_t> Circle2ul;
	typedef Circle2<int64_t> Circle2l;
}

#endif
