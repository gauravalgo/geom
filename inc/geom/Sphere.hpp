
/**
 * \file Sphere.hpp
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

#ifndef GEOM_SPHERE_HPP
#define GEOM_SPHERE_HPP

#include <cstdint>
#include "Point3.hpp"

namespace geom {
	template <typename Scalar>
	class Sphere {
	public:
		Sphere(const Point3<Scalar> &center, const Scalar &radius) :
			radius(radius), center(center)
		{ }
		template <typename Type1, typename Type2>
		Sphere(const Point3<Type1> &center, const Type2 &radius) :
			radius(radius), center(center)
		{ }
		Sphere(const Sphere<Scalar> &source) :
			radius(source.radius), center(source.center)
		{ }
		template <typename Other>
		Sphere(const Sphere<Other> &source) :
			radius(source.radius), center(source.center)
		{ }
		~Sphere() { }
		
		Scalar radius;
		Point3<Scalar> center;
	};
	
	typedef Sphere<double> Sphere3d;
	typedef Sphere<float> Sphere3f;
	typedef Sphere<std::uint32_t> Sphere3u;
	typedef Sphere<std::int32_t> Sphere3i;
	typedef Sphere<std::uint64_t> Sphere3ul;
	typedef Sphere<std::int64_t> Sphere3l;
}

#endif
