
/**
 * \file Line2.hpp
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

#ifndef GEOM_LINE_3_HPP
#define GEOM_LINE_3_HPP

#include <cstdint>
#include "Point2.hpp"

namespace geom {
	template <typename Scalar>
	struct Line2 {
		Line2(const Scalar &x1, const Scalar &y1, const Scalar &x2,
					const Scalar &y2) :
			p1(x1,y1), p2(x2,y2)
		{ }
		template <typename Type1, typename Type2>
		Line2(const Point2<Type1> &p1, const Point2<Type2> &p2) :
			p1(p1), p2(p2)
		{ }
		Line2(const Line2<Scalar> &source) :
			p1(source.p1), p2(source.p2)
		{ }
		template <typename Other>
		Line2(const Line2<Other> &source) :
			p1(source.p1), p2(source.p2)
		{ }
		~Line2() { }
		
		Line2<Scalar> & operator=(const Line2<Scalar> &source) {
			p1 = source.p1;
			p2 = source.p2;
			return *this;
		}
		
		template <typename Other>
		Line2<Scalar> & operator=(const Line2<Other> &source) {
			p1 = source.p1;
			p2 = source.p2;
		}
		
		Point2<Scalar> p1, p2;
	};
	
	typedef Line2<double> Line2d;
	typedef Line2<float> Line2f;
	typedef Line2<std::uint32_t> Line2u;
	typedef Line2<std::int32_t> Line2i;
	typedef Line2<std::uint64_t> Line2ul;
	typedef Line2<std::int64_t> Line2l;
}

#endif
