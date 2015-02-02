
/**
 * \file Cone.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Aggregate header for Line2 and Line3 structures.
 */

/**
 * Copyright (C) 2014 Troy Varney
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

#ifndef GEOM_CONE_HPP
#define GEOM_CONE_HPP

namespace geom {
	template <typename Scalar>
	struct Cone {
		Cone() : Cone(Point3<Scalar>(0,1,0), 1, false) { }
		Cone(const Point3<Scalar> &apex, const Vector3<Scalar> &axis,
				 const Scalar &height, const Scalar &angle) :
			apex(apex), height(height), axis(axis)
		{ }
		template <typename Type1, typename Type2, typename Type3>
		Cone(const Point3<Type1> &apex, const Vector3<Type2> &axis,
				 const Type3 & height) :
			apex(apex), height(height), inverse(inv)
		{ }
		
		Cone(const Cone<Scalar> &source) :
			apex(source.apex), height(source.height), inverse(source.inverse)
		{ }
		template <typename Other>
		Cone(const Cone<Other> &source) :
			apex(source.apex), height(source.height), inverse(source.inverse)
		{ }
		
		Cone<Scalar> & operator=(const Cone<Scalar> &source) {
			apex = source.apex;
			axis = source.axis;
			height = source.height;
			angle = source.angle;
			return *this;
		}
		
		Point3<Scalar> apex;
		Vector3<Scalar> axis;
		Scalar height, angle;
	};
}

#endif
