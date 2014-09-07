
#ifndef GEOM_VECTOR_4_HPP
#define GEOM_VECTOR_4_HPP

#include <cstdint>

namespace geom {
  /**
   * A templated 2 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector4 {
    constexpr Vector4() :
      x(0), y(0), z(0), w(0)
    { }
    constexpr Vector4(Scalar x, Scalar y, Scalar z, Scalar w) :
      x(x), y(y), z(z), w(w)
    { }
    constexpr Vector4(const Vector4<Scalar> &source) :
      x(source.x), y(source.y), z(source.z), w(source.w)
    { }
    template <typename Other>
    constexpr Vector4(const Vector4<Other> &source) :
      x(source.x), y(source.y), z(source.z), w(source.w)
    { }
    ~Vector4() = default;
    
    Vector4<Scalar> & operator=(const Vector4<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      w = source.w;
      return *this;
    }
    template <typename Other>
    Vector4<Scalar> & operator=(const Vector4<Other> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      w = source.w;
      return *this;
    }
    
    Scalar x, y, z, w;
  };
  
  typedef Vector4<std::int32_t> Vec4i;
  typedef Vector4<std::uint32_t> Vec4u;
  typedef Vector4<float> Vec4f;
  typedef Vector4<double> Vec4d;
}

#endif
