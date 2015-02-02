
/**
 * \file Ray.hpp
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

#ifndef GEOM_RAY_HPP
#define GEOM_RAY_HPP

namespace geom {
	/**
	 * \brief An object that represents an infinite length line from an origin.
	 */
	template <typename Scalar>
	struct Ray {
		/**
		 * \brief Create a ray from (0,0,0) along the z axis.
		 */
		Ray() : Ray(Point3<Scalar>(0,0,0), Vector3<Scalar>(0,0,1)) { }
		/**
		 * \brief Create a ray with the given origin and direction.
		 * \arg \c origin The origin of the ray
		 * \arg \c direction The normal vector denoting the direction of the ray.
		 */
		Ray(const Point3<Scalar> &origin, const Vector3<Scalar> &direction) :
			origin(origin), direction(direction)
		{ }
		/**
		 * \brief Create a ray with the given origin and direction.
		 * 
		 * This constructor will convert types as needed.
		 * 
		 * \arg \c origin The origin of the ray
		 * \arg \c direction The normal vector denoting the direction of the ray.
		 */
		template <typename Type1, typename Type2>
		Ray(const Point3<Type1> &origin, const Vector3<Type2> &direction) :
			origin(origin), direction(direction)
		{ }
		/**
		 * \brief Construct a copy of the given ray.
		 * \arg \c source The ray to copy
		 */
		Ray(const Ray<Scalar> &source) :
			origin(source.origin), direction(source.direction)
		{ }
		/**
		 * \brief Construct a converted copy of the given ray.
		 * 
		 * This constructor will convert types as needed.
		 * 
		 * \arg \c source The ray to copy
		 */
		template <typename Other>
		Ray(const Ray<Other> &source) :
			origin(source.origin), direction(source.direction)
		{ }
		
		/**
		 * \brief Copy the given ray.
		 * \arg \c source The source ray to copy
		 */
		Ray<Scalar> & operator=(const Ray<Scalar> &source) {
			origin = source.origin;
			direction = source.direction;
			return *this;
		}
		/**
		 * \brief Copy and convert the given ray.
		 * 
		 * This method will convert types as needed.
		 * 
		 * \arg \c source The source ray to copy.
		 */
		template <typename Other>
		Ray<Scalar> & operator=(const Ray<Other> &source) {
			origin = source.origin;
			direction = source.direction;
			return *this;
		}
	};
	
	/**
	 * \brief Convert Ray into object space coordinates using the reference
	 * origin.
	 * 
	 * \arg \c ray The ray to transform into object space.
	 * \arg \c origin The origin of the object space.
	 * \return A new Ray object of the same type which is transformed into object
	 * space.
	 */
	template <typename Type1, typename Type2>
	Ray<Type1> transform(const Ray<Type1> &ray, const Point3<Type2> &origin) {
		return Ray<Type1>(Point3<Type1>(ray.origin.x - origin.x,
																		ray.origin.y - origin.y,
																		ray.origin.z - origin.z),
											ray.direction);
	}
	
	/**
	 * \brief Move the origin of the ray the given distance in its direction.
	 * 
	 * \arg \c ray The ray to project.
	 * \arg \c distance How far along the ray to move its origin.
	 * \return A new ray object moved the given distance along its direction
	 */
	template <typename Type1, typename Type2>
	Ray<Type1> project(const Ray<Type1> &ray, const Type2 & distance) {
		return Ray<Type1>(ray.origin + (ray.direction * distance), ray.direction);
	}
}

#endif
