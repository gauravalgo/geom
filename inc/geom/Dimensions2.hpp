
#ifndef GEOM_DIMENSIONS_2_HPP
#define GEOM_DIMENSIONS_2_HPP

#include <cstdint>

namespace geom {
  template <typename Scalar>
  struct Dimensions2 {
    Dimensions2() :
      width(0), height(0)
    { }
    Dimensions2(Scalar width, Scalar height) :
      width(width), height(height)
    { }
    Dimensions2(const Dimensions2<Scalar> &source) :
      width(source.width), height(source.height)
    { }
    template <typename Other>
    Dimensions2(const Dimensions2<Other> &source) :
      width(source.width), height(source.height)
    { }
    
    ~Dimensions2() = default;
    
    Dimensions2<Scalar> & operator=(const Dimensions2<Scalar> &source) {
      width = source.width;
      height = source.height;
      return *this;
    }
    
    template <typename Other>
    Dimensions2<Scalar> & operator=(const Dimensions2<Other> &source) {
      width = static_cast<Scalar>(source.width);
      height = static_cast<Scalar>(source.height);
      return *this;
    }
    
    Scalar width, height;
  };
  
  typedef Dimensions2<std::int32_t> Dimensions2i;
  typedef Dimensions2<std::uint32_t> Dimensions2u;
  typedef Dimensions2<float> Dimensions2f;
  typedef Dimensions2<double> Dimensions2d;
}

#endif
