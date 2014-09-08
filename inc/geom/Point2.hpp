
/**
 * \file Point2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header for Point2 structure
 */

/**
 * Copyright (C) 2014 Troy Varney
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

#ifndef GEOM_POINT_2_HPP
#define GEOM_POINT_2_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A point in 2 dimensional space.
   */
  template <typename Scalar>
  struct Point2 {
    /**
     * \brief Construct a point at the origin
     */
    Point2() :
      x(0), y(0)
    { }
    /**
     * \brief Construct a point with the given coordinates.
     * \arg \c x The x coordinate of the \c Point2
     * \arg \c y The y coordinate of the \c Point2
     */
    Point2(Scalar x, Scalar y) :
      x(x), y(y)
    { }
    /**
     * \brief Construct a point at the same location as the given \c Point2
     * object.
     * \arg \c source The \c Point2 to copy
     */
    Point2(const Point2<Scalar> &source) :
      x(source.x), y(source.y)
    { }
    /**
     * \brief Construct a point which is a conversion of the given \c Point2
     * object.
     * \arg \c source The \c Point2 object to convert from
     */
    template <typename Other>
    Point2(const Point2<Other> &source) :
      x(source.x), y(source.y)
    { }
    ~Point2() = default;
    
    /**
     * \brief Assign coordinate values from the given \c Point2 object
     * \arg \c source The \c Point2 object to assign from
     * \return A reference to the \c Point2 object being assigned to
     */
    Point2<Scalar> & operator=(const Point2<Scalar> &source) {
      x = source.x;
      y = source.y;
      return *this;
    }
    
    /**
     * \brief Convert and assign coordinate values from the given \c Point2
     * object.
     * \arg \c source The \c Point2 object to convert and assign from
     * \return A reference to the \c Point2 object being assigned to
     */
    template <typename Other>
    Point2<Scalar> & operator=(const Point2<Other> &source) {
      x = static_cast<Scalar>(source.x);
      y = static_cast<Scalar>(source.y);
      return *this;
    }
    
    Scalar x; /**< The x coordinate of the \c Point2 object */
    Scalar y; /**< The y coordinate of the \c Point2 object */
  };
  
  typedef Point2<std::int32_t> Point2i;
  typedef Point2<std::uint32_t> Point2u;
  typedef Point2<float> Point2f;
  typedef Point2<double> Point2d;
}

#endif
