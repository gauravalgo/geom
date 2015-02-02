
/**
 * \file Plane.hpp
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

#ifndef GEOM_PLANE_HPP
#define GEOM_PLANE_HPP

#include "Vector3.hpp"

namespace geom {
	template <typename Scalar>
	struct Plane {
		/**
		 * \brief Create an infinite plane facing 'up' and not offset.
		 */
		Plane() :
			normal(0,1,0), offset(0)
		{ }
		/**
		 * \brief Create an infinite plane from the given normal and offset.
		 * 
		 * Types match, optimized path.
		 * 
		 * \arg \c normal The normal vector of the plane.
		 * \arg \c offset How far along the normal the plane is offset.
		 */
		Plane(const Vector3<Scalar> &normal, Scalar offset) :
			normal(normal), offset(offset)
		{ }
		/**
		 * \brief Create an infinite plane from the given normal and offset.
		 * 
		 * Types don't match, conversion happens.
		 * 
		 * \arg \c normal The normal vector of the plane.
		 * \arg \c offset How far along the normal the plane is offset.
		 */
 		template <typename Type1, typename Type2>
		Plane(const Vector3<Type1> &normal, Type2 offset) :
			normal(normal), offset(Scalar(offset))
		{ }
		/**
		 * \brief Create a copy of the given infinite plane.
		 * 
		 * \arg \c source The source plane to copy.
		 */
		Plane(const Plane<Scalar> &source) :
			normal(source.normal), offset(source.offset)
		{ }
		/**
		 * \brief Create a copy of teh given infinite plane, converted to our type.
		 * 
		 * Conversion between types may happen.
		 * 
		 * \arg \c source The source plane to copy and convert.
		 */
		template <typename Other>
		Plane(const Plane<Other> &source) :
			normal(source.normal), offset(source.offset)
		{ }
		
		/**
		 * \brief Copy the given plane
		 * 
		 * \arg \c source The plane to copy.
		 * \return A reference to this object.
		 */
		Plane<Scalar> & operator=(const Plane<Scalar> &source) {
			normal = source.normal;
			offset = source.offset;
			return *this;
		}
		/**
		 * \brief Copy the given plane, converting types.
		 * 
		 * \arg \c source The plane to copy and convert.
		 * \return A reference to this object.
		 */
		template <typename Other>
		Plane<Scalar> & operator=(const Plane<Other> &source) {
			normal = source.normal;
			offset = source.offset;
			return *this;
		}
		
		//bool intersect(const Ray &source, Ray &result) const;
		//bool bisect(const Ray &source, Ray &result) const;
		
		Vector3<Scalar> normal;
		Scalar offset;
	};
}

#endif
