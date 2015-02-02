
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
	
	typedef Sphere<Double> Sphere3d;
	typedef Sphere<float> Sphere3f;
	typedef Sphere<std::uint32_t> Sphere3u;
	typedef Sphere<std::int32_t> Sphere3i;
	typedef Sphere<std::uint64_t> Sphere3ul;
	typedef Sphere<std::int64_t> Sphere3l;
}

#endif
