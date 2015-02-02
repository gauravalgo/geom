
/**
 * \file Point3.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Point3 structure
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

#ifndef GEOM_POINT_3_HPP
#define GEOM_POINT_3_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A point in 3 dimensional space.
   */
  template <typename Scalar>
  struct Point3 {
    /**
     * \brief Construct a \c Point3 at the origin (0,0,0)
     */
    Point3() :
      x(0), y(0), z(0)
    { }
    /**
     * \brief Construct a \c Point3 at the given coordinates
     * \arg \c x The x coordinate of the \c Point3 object
     * \arg \c y The y coordinate of the \c Point3 object
     * \arg \c z The z coordinate of the \c Point3 object
     */
    Point3(Scalar x, Scalar y, Scalar z) :
      x(x), y(y), z(z)
    { }
    /**
     * \brief Construct a \c Point3 at the same location as the given
     * \c Point3.
     * /arg \c source The \c Point3 to copy the location from
     */
    Point3(const Point3<Scalar> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    /**
     * \brief Construct a \c Point3 which is a conversion of the given
     * \c Point3 object.
     * \arg \c source The \c Point3 to convert the location from
     */
    template <typename Other>
    Point3(const Point3<Other> &source) :
      x(source.x), y(source.y), z(source.z)
    { }
    ~Point3() = default;
    
    /**
     * \brief Assign location from the given \c Point3
     * \arg \c source The \c Point3 to assign location from
     * \return A refernce to the \c Point3 being assigned to
     */
    Point3<Scalar> & operator=(const Point3<Scalar> &source) {
      x = source.x;
      y = source.y;
      z = source.z;
      return *this;
    }
    
    /**
     * \brief Assign converted location from the given \c Point3
     * \arg \c source The \c Point3 to convert the location from
     * \return A reference to the \c Point3 being assigned to
     */
    template <typename Other>
    Point3<Scalar> & operator=(const Point3<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      z = static_cast<Scalar>(source.z);
      return *this;
    }
    
    Scalar x; /**< The x coordinate of the \c Point3 object */
    Scalar y; /**< The y coordinate of the \c Point3 object */
    Scalar z; /**< The z coordinate of the \c Point3 object */
  };
  
  typedef Point3<std::int32_t> Point3i;
  typedef Point3<std::uint32_t> Point3u;
  typedef Point3<std::int64_t> Point3l;
  typedef Point3<std::uint64_t> Point3ul;
  typedef Point3<float> Point3f;
  typedef Point3<double> Point3d;
}

#endif
