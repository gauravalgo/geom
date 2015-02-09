
#ifndef GEOM_RECTANGLE3_HPP
#define GEOM_RECTANGLE3_HPP

#include "Point3.hpp"
#include "Dimensions2.hpp"
#include "Vector3.hpp"

namespace geom {
	template <typename Scalar>
	struct Rectangle3 {
		Rectangle3() : origin(0,0,0), dim(1,1), normal(0,1,0) { }
		Rectangle3(const Point3<Scalar> &origin, const Dimensions2<Scalar> &dim,
							 const Vector3<Scalar> &normal) :
			origin(origin), dim(dim), normal(normal)
		{ }
		Rectangle3(const Rectangle3<Scalar> &source) :
			origin(source.origin), dim(source.dim), normal(source.normal)
		{ }
		template <typename T>
		Rectangle3(const Rectangle3<T> &source) :
			origin(source.origin), dim(source.dim), normal(source.normal)
		{ }
		~Rectangle3() { }
		
		Point3<Scalar> origin;
		Dimensions2<Scalar> dim;
		Vector3<Scalar> normal;
	};
}

#endif
