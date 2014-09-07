
#ifndef GEOM_VECTOR_3_HPP
#define GEOM_VECTOR_3_HPP

#include <cstdint>

namespace geom {
  /**
   * A templated 2 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector3 {
    constexpr Vector3() :
      x(0), y(0), z(0)
    { }
    constexpr Vector3(Scalar x, Scalar y, Scalar z) :
      x(x), y(y), z(z)
    { }
    constexpr Vector3(const Vector3<Scalar> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    template <typename Other>
    constexpr Vector3(const Vector3<Other> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    ~Vector3() = default;
    
    Vector3<Scalar> & operator=(const Vector3<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    template <typename Other>
    Vector3<Scalar> & operator=(const Vector3<Other> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    
    Scalar x, y, z;
  };
  
  typedef Vector3<std::int32_t> Vec2i;
  typedef Vector3<std::uint32_t> Vec2u;
  typedef Vector3<float> Vec2f;
  typedef Vector3<double> Vec2d;
}

#endif
