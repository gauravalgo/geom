
#ifndef GEOM_POINT_2_HPP
#define GEOM_POINT_2_HPP

#include <cstdint>

namespace geom {
  template <typename Scalar>
  struct Point2 {
    Point2() :
      x(0), y(0)
    { }
    Point2(Scalar x, Scalar y) :
      x(x), y(y)
    { }
    Point2(const Point2<Scalar> &source) :
      x(source.x), y(source.y)
    { }
    template <typename Other>
    Point2(const Point2<Other> &source) :
      x(source.x), y(source.y)
    { }
    ~Point2() = default;
    
    Point2<Scalar> & operator=(const Point2<Scalar> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    
    template <typename Other>
    Point2<Scalar> & operator=(const Point2<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      return *this;
    }
    
    Scalar x, y;
  };
  
  typedef Point2<std::int32_t> Point2i;
  typedef Point2<std::uint32_t> Point2u;
  typedef Point2<float> Point2f;
  typedef Point2<double> Point2d;
}

#endif
