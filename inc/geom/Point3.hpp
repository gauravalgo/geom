
#ifndef GEOM_POINT_3_HPP
#define GEOM_POINT_3_HPP

#include <cstdint>

namespace geom {
  template <typename Scalar>
  struct Point3 {
    Point3() :
      x(0), y(0), z(0)
    { }
    Point3(Scalar x, Scalar y, Scalar z) :
      x(x), y(y), z(z)
    { }
    Point3(const Point3<Scalar> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    template <typename Other>
    Point3(const Point3<Other> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    ~Point3() = default;
    
    Point3<Scalar> & operator=(const Point3<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    
    template <typename Other>
    Point3<Scalar> & operator=(const Point3<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      z = static_cast<Scalar>(source.z);
      return *this;
    }
    
    Scalar x, y, z;
  };
  
  typedef Point3<std::int32_t> Point3i;
  typedef Point3<std::uint32_t> Point3u;
  typedef Point3<float> Point3f;
  typedef Point3<double> Point3d;
}

#endif
