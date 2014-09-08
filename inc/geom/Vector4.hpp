
/**
 * \file Vector4.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Vector4 structure
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

#ifndef GEOM_VECTOR_4_HPP
#define GEOM_VECTOR_4_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A templated 4 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector4 {
    /**
     * \brief Construct a \c Vector4 object with 0 length
     */
    constexpr Vector4() :
      x(0), y(0), z(0), w(0)
    { }
    /**
     * \brief Construct a \c Vector4 object with the given dimensions
     * \arg \c x The x component of the \c Vector4
     * \arg \c y The y component of the \c Vector4
     * \arg \c z The z component of the \c Vector4
     * \arg \c w The w component of the \c Vector4
     */
    constexpr Vector4(Scalar x, Scalar y, Scalar z, Scalar w) :
      x(x), y(y), z(z), w(w)
    { }
    /**
     * \brief Construct a \c Vector4 which is a copy of the given \c Vector4
     * reference.
     * \arg \c source The \c Vector4 to copy from
     */
    constexpr Vector4(const Vector4<Scalar> &source) :
      x(source.x), y(source.y), z(source.z), w(source.w)
    { }
    /**
     * \brief Construct a \c Vector4 which is a conversion of the given
     * \c Vector4 reference.
     * \arg \c source The \c Vector4 to convert from
     */
    template <typename Other>
    constexpr Vector4(const Vector4<Other> &source) :
      x(source.x), y(source.y), z(source.z), w(source.w)
    { }
    ~Vector4() = default;
    
    /**
     * \brief Assign value from the given \c Vector4 object
     * \arg \c source The \c Vector4 to assign from
     * \return A reference to the \c Vector4 being assigned to
     */
    Vector4<Scalar> & operator=(const Vector4<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      w = source.w;
      return *this;
    }
    /**
     * \brief Convert and assign value from the given \c Vector4 object
     * \arg \c source The \c Vector4 to assign converted values from
     * \return A reference to the \c Vector4 being assigned to
     */
    template <typename Other>
    Vector4<Scalar> & operator=(const Vector4<Other> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      w = source.w;
      return *this;
    }
    
    Scalar x; /**< The x component of the \c Vector4 object */
    Scalar y; /**< The y component of the \c Vector4 object */
    Scalar z; /**< The z component of the \c Vector4 object */
    Scalar w; /**< The w component of the \c Vector4 object */
  };
  
  typedef Vector4<std::int32_t> Vec4i;
  typedef Vector4<std::uint32_t> Vec4u;
  typedef Vector4<float> Vec4f;
  typedef Vector4<double> Vec4d;
}

#endif
