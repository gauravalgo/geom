
/**
 * \file Vector3.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Vector3 structure
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

#ifndef GEOM_VECTOR_3_HPP
#define GEOM_VECTOR_3_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A templated 3 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector3 {
    /**
     * \brief Construct a \c Vector3 of 0 length
     * 
     * This constructor sets all components of the \c Vector3 object created to
     * be Scalar(0); that is, for any integral type each component is 0.
     */
    constexpr Vector3() :
      x(0), y(0), z(0)
    { }
    /**
     * \brief Construct a \c Vector3 with the given components
     * \arg \c x The x component of the \c Vector3
     * \arg \c y The y component of the \c Vector3
     * \arg \c z The z component of the \c Vector3
     */
    constexpr Vector3(Scalar x, Scalar y, Scalar z) :
      x(x), y(y), z(z)
    { }
    /**
     * \brief Construct a \c Vector3 that is a copy of the given \c Vector3
     * object.
     * \arg \c source The \c Vector3 object to copy
     */
    constexpr Vector3(const Vector3<Scalar> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    /**
     * \brief Construct a \c Vector3 that is a conversion of the given
     * \c Vector3 object.
     * \arg \c source The \c Vector3 object to convert
     */
    template <typename Other>
    constexpr Vector3(const Vector3<Other> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    ~Vector3() = default;
    
    /**
     * \brief Assign components from the given \c Vector3
     * \arg \c source The \c Vector3 to assign values from
     * \return A reference to the \c Vector3 object being assigned to
     */
    Vector3<Scalar> & operator=(const Vector3<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    /**
     * \brief Assign converted components from the given \c Vector3
     * \arg \c source The \c Vector3 to convert values from
     */
    template <typename Other>
    Vector3<Scalar> & operator=(const Vector3<Other> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    
    /**
     * \brief Assign the result of adding two vectors.
     * \arg \c rhs The vector to add to this \c Vector3 object
     * \return A reference to the \c Vector3 object being assigned to
     */
    Vector3<Scalar> & operator+=(const Vector3<Scalar> &rhs) {
      return *this = *this + rhs;
    }

    
    Scalar x; /**< The x component of the \c Vector3 object */
    Scalar y; /**< The y component of the \c Vector3 object */
    Scalar z; /**< The z component of the \c Vector3 object */
  };
  
  typedef Vector3<std::int32_t> Vec3i;
  typedef Vector3<std::uint32_t> Vec3u;
  typedef Vector3<float> Vec3f;
  typedef Vector3<double> Vec3d;
  
  /**
   * \brief Add two \c Vector3 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the addition symbol
   * \arg \c rhs The operand on the right hand side of the addition symbol
   * \return A new \c Vector3 object that contains the result of adding lhs and
   * rhs
   */
  template <typename RhsType, typename LhsType,
	    typename Result = typename std::common_type<RhsType,LhsType>::type>
  Vector3<Result> operator+(const Vector3<LhsType> &lhs,
			    const Vector3<RhsType> &rhs)
  {
    return Vector3<Result>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
  }
}

#endif
