
#ifndef GEOM_VECTOR_2_HPP
#define GEOM_VECTOR_2_HPP

#include <cstdint>

namespace geom {
  /**
   * A templated 2 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector2 {
    constexpr Vector2() :
      x(0), y(0)
    { }
    constexpr Vector2(Scalar x, Scalar y) :
      x(x), y(y)
    { }
    constexpr Vector2(const Vector2<Scalar> &source) :
      x(source.x), y(source.y)
    { }
    template <typename Other>
    constexpr Vector2(const Vector2<Other> &source) :
      x(source.x), y(source.y)
    { }
    ~Vector2() = default;
    
    Vector2<Scalar> & operator=(const Vector2<Scalar> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    template <typename Other>
    Vector2<Scalar> & operator=(const Vector2<Other> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    
    Scalar x, y;
  };
  
  typedef Vector2<std::int32_t> Vec2i;
  typedef Vector2<std::uint32_t> Vec2u;
  typedef Vector2<float> Vec2f;
  typedef Vector2<double> Vec2d;
}

#endif
