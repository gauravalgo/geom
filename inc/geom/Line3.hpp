
/**
 * \file Line3.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Line3 structure
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

#ifndef GEOM_LINE_3_HPP
#define GEOM_LINE_3_HPP

#include <cstdint>
#include "Point3.hpp"

namespace geom {
	template <typename Scalar>
	struct Line3 {
		Line3(const Scalar &x1, const Scalar &y1, const Scalar &x2,
					const Scalar &y2) :
			p1(x1,y1), p2(x2,y2)
		{ }
		template <typename Type1, typename Type2>
		Line3(const Point3<Type1> &p1, const Point3<Type2> &p2) :
			p1(p1), p2(p2)
		{ }
		Line3(const Line3<Scalar> &source) :
			p1(source.p1), p2(source.p2)
		{ }
		template <typename Other>
		Line3(const Line3<Other> &source) :
			p1(source.p1), p2(source.p2)
		{ }
		~Line3() { }
		
		Line3<Scalar> & operator=(const Line3<Scalar> &source) {
			p1 = source.p1;
			p2 = source.p2;
			return *this;
		}
		
		template <typename Other>
		Line3<Scalar> & operator=(const Line3<Other> &source) {
			p1 = source.p1;
			p2 = source.p2;
		}
		
		Point3<Scalar> p1, p2;
	};
	
	typedef Line3<double> Line3d;
	typedef Line3<float> Line3f;
	typedef Line3<std::uint32_t> Line3u;
	typedef Line3<std::int32_t> Line3i;
	typedef Line3<std::uint64_t> Line3ul;
	typedef Line3<std::int64_t> Line3l;
}

#endif
