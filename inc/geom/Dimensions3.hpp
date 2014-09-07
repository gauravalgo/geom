
#ifndef GEOM_DIMENSIONS_3_HPP
#define GEOM_DIMENSIONS_3_HPP

#include <cstdint>

namespace geom {
  template <typename Scalar>
  struct Dimensions3 {
    Dimensions3() :
      width(0), height(0), depth(0)
    { }
    Dimensions3(Scalar width, Scalar height, Scalar depth) :
      width(width), height(height), depth(depth)
    { }
    Dimensions3(const Dimensions3<Scalar> &source) :
      width(source.width), height(source.height), depth(source.depth)
    { }
    template <typename Other>
    Dimensions3(const Dimensions3<Other> &source) :
      width(source.width), height(source.height), depth(source.depth)
    { }
    
    ~Dimensions3() = default;
    
    Dimensions3<Scalar> & operator=(const Dimensions3<Scalar> &source) {
      width = source.width;
      height = source.height;
      depth = source.depth;
      return *this;
    }
    
    template <typename Other>
    Dimensions3<Scalar> & operator=(const Dimensions3<Other> &source) {
      width = static_cast<Scalar>(source.width);
      height = static_cast<Scalar>(source.height);
      depth = static_cast<Scalar>(source.depth);
      return *this;
    }
    
    Scalar width, height, depth;
  };
  
  typedef Dimensions3<std::int32_t> Dimensions3i;
  typedef Dimensions3<std::uint32_t> Dimensions3u;
  typedef Dimensions3<float> Dimensions3f;
  typedef Dimensions3<double> Dimensions3d;
}

#endif
