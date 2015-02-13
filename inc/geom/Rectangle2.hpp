
#ifndef GEOM_RECTANGLE2_HPP
#define GEOM_RECTANGLE2_HPP

#include "Point2.hpp"
#include "Dimensions2.hpp"

namespace geom {
	template <typename Scalar>
	struct Rectangle2 {
	public:
		Rectangle2() : origin(0,0), dim(1,1) { }
		Rectangle2(Scalar x, Scalar y, Scalar width, Scalar height) :
			origin(x,y), dim(width,height)
		{ }
		Rectangle2(const Point2<Scalar> &origin, const Dimensions2<Scalar> &dim) :
			origin(origin), dim(dim)
		{ }
		Rectangle2(const Rectangle2<Scalar> &source) :
			origin(source.origin), dim(source.dim)
		{ }
		template <typename T>
		Rectangle2(const Rectangle2<T> &source) :
			origin(source.origin), dim(source.dim)
		{ }
		~Rectangle2() { }
		
		Point2<Scalar> origin;
		Dimensions2<Scalar> dim;
	};
	
	typedef Rectangle2<float> Rectangle2f;
	typedef Rectangle2<double> Rectangle2d;
	typedef Rectangle2<int32_t> Rectangle2i;
	typedef Rectangle2<uint32_t> Rectangle2u;
	typedef Rectangle2<int64_t> Rectangle2l;
	typedef Rectangle2<uint64_t> Rectangle2ul;
}

#endif
