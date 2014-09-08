
/**
 * \file Vector2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header of Vector2 structure.
 */

/* Copyright (C) 2014 Troy Varney
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef GEOM_VECTOR_2_HPP
#define GEOM_VECTOR_2_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A templated 2 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector2 {
    /**
     * \brief Construct a \c Vector2 with 0 length
     */
    constexpr Vector2() :
      x(0), y(0)
    { }
    /**
     * \brief Construct a \c Vector2 with the given components
     * \arg \c x The x component of the \c Vector2 object
     * \arg \c y The y component of the \c Vector2 object
     */
    constexpr Vector2(Scalar x, Scalar y) :
      x(x), y(y)
    { }
    /**
     * \brief Construct a \c Vector2 object which is a copy of the given
     * \c Vector2 object.
     * \arg \c source The \c Vector2 object to copy
     */
    constexpr Vector2(const Vector2<Scalar> &source) :
      x(source.x), y(source.y)
    { }
    /**
     * \brief Construct a \c Vector2 object which is a converted copy of the
     * given \c Vector2 object.
     * \arg \c source The \c Vector2 object to convert from
     */
    template <typename Other>
    constexpr Vector2(const Vector2<Other> &source) :
      x(source.x), y(source.y)
    { }
    ~Vector2() = default;
    
    /**
     * \brief Assign value from the given \c Vector2 object.
     * \arg \c source The \c Vector2 object to assign values from
     * \return A reference to the \c Vector2 object being assigned to
     */
    Vector2<Scalar> & operator=(const Vector2<Scalar> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    /**
     * \brief Assign converted value from the given \c Vector2 object.
     * \arg \c source The \c Vector2 obejct to assign converted values from
     * \return A reference to the \c Vector2 object being assigned to
     */
    template <typename Other>
    Vector2<Scalar> & operator=(const Vector2<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      return *this;
    }
    
    Scalar x; /**< The x component of the \c Vector2 object */
    Scalar y; /**< The y component of the \c Vector2 object */
  };
  
  typedef Vector2<std::int32_t> Vec2i;
  typedef Vector2<std::uint32_t> Vec2u;
  typedef Vector2<float> Vec2f;
  typedef Vector2<double> Vec2d;
}

#endif
