
/**
 * \file Dimensions3.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header of Dimensions3 structure
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

#ifndef GEOM_DIMENSIONS_3_HPP
#define GEOM_DIMENSIONS_3_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A representation of a measurement in 3 dimensions
   */
  template <typename Scalar>
  struct Dimensions3 {
    /**
     * \brief Construct a \c Dimensions3 object with measurements of 0 in all
     * dimensions.
     */
    Dimensions3() :
      width(0), height(0), depth(0)
    { }
    /**
     * \brief Construct a \c Dimensions3 object with the given width, height,
     * and depth.
     * \arg \c width The width of the new \c Dimensions3 object.
     * \arg \c height The height of the new \c Dimensions3 object.
     * \arg \c depth The depth of the new \c Dimensions3 object.
     */
    Dimensions3(Scalar width, Scalar height, Scalar depth) :
      width(width), height(height), depth(depth)
    { }
    /**
     * \brief Construct a \c Dimensions3 object that is a copy of the given
     * \c Dimensions3 reference.
     * \arg \c source The \c Dimensions3 object to copy from.
     */
    Dimensions3(const Dimensions3<Scalar> &source) :
      width(source.width), height(source.height), depth(source.depth)
    { }
    /**
     * \brief Constructs a \c Dimensions3 object that is a conversion of the
     * given \c Dimensions3 reference.
     * \arg \c source The \c Dimensions3 object to copy from.
     */
    template <typename Other>
    Dimensions3(const Dimensions3<Other> &source) :
      width(source.width), height(source.height), depth(source.depth)
    { }
    
    ~Dimensions3() = default;
    
    /**
     * \brief Assign value to this \c Dimensions3 object from the given
     * \c Dimensions3 object.
     * \arg \c source The Dimensions3 object to assign from.
     * \return A reference to this \c Dimensions3 object.
     */
    Dimensions3<Scalar> & operator=(const Dimensions3<Scalar> &source) {
      width = source.width;
      height = source.height;
      depth = source.depth;
      return *this;
    }
    
    /**
     * \brief Assign value to this \c Dimensions3 object converted from the
     * given \c Dimensions3 object.
     * \arg \c source The \c Dimensions3 object to assign from.
     */
    template <typename Other>
    Dimensions3<Scalar> & operator=(const Dimensions3<Other> &source) {
      width = static_cast<Scalar>(source.width);
      height = static_cast<Scalar>(source.height);
      depth = static_cast<Scalar>(source.depth);
      return *this;
    }
    
    Scalar width; /**< The width of the \c Dimensions3 object */
    Scalar height; /**< The height of the \c Dimensions3 object */
    Scalar depth; /**< The depth of the \c Dimensions3 object */
  };
  
  typedef Dimensions3<std::int32_t> Dimensions3i;
  typedef Dimensions3<std::uint32_t> Dimensions3u;
  typedef Dimensions3<float> Dimensions3f;
  typedef Dimensions3<double> Dimensions3d;
}

#endif
