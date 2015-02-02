
/**
 * \file Dimensions2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
 * \brief Definition header of Dimensions2 structure.
 */

/*  Copyright (C) 2014 Troy Varney
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

#ifndef GEOM_DIMENSIONS_2_HPP
#define GEOM_DIMENSIONS_2_HPP

#include <cstdint>

namespace geom {
  /**
   * \brief A representation of measurement in two dimensions
   */
  template <typename Scalar>
  struct Dimensions2 {
    /**
     * \brief Construct a \c Dimensions2 object with values of 0 for both
     * dimensions.
     */
    Dimensions2() :
      width(0), height(0)
    { }
    /**
     * \brief Construct a \c Dimensions2 object with the given width and
     * height.
     * \arg \c width The width of the new \c Dimensions2
     * \arg \c height The height of the new \c Dimensions2
     */
    Dimensions2(Scalar width, Scalar height) :
      width(width), height(height)
    { }
    /**
     * \brief Construct a \c Dimensions2 object that is a copy of the given
     * reference.
     * \arg \c source The \c Dimensions2 object to copy
     */
    Dimensions2(const Dimensions2<Scalar> &source) :
      width(source.width), height(source.height)
    { }
    /**
     * \brief Construct a \c Dimensions2 object that is a conversion of the
     * given reference.
     * \arg \c source The \c Dimensions2 object to copy and convert
     */
    template <typename Other>
    Dimensions2(const Dimensions2<Other> &source) :
      width(source.width), height(source.height)
    { }
    
    ~Dimensions2() = default;
    
    /**
     * \brief Assign value from the given \c Dimensions2 object.
     * \arg \c source The \c Dimensions2 object to assign from.
     */
    Dimensions2<Scalar> & operator=(const Dimensions2<Scalar> &source) {
      width = source.width;
      height = source.height;
      return *this;
    }
    
    /**
     * \brief Assign converted values from the given \c Dimensions2 object.
     * \arg \c source The \c Dimensions2 object to convert and assign from.
     */
    template <typename Other>
    Dimensions2<Scalar> & operator=(const Dimensions2<Other> &source) {
      width = static_cast<Scalar>(source.width);
      height = static_cast<Scalar>(source.height);
      return *this;
    }
    
    Scalar width; /**< The width of the \c Dimensions2 object. */
    Scalar height; /**< The height of the \c Dimensions2 object. */
  };
  
  typedef Dimensions2<std::int32_t> Dimensions2i;
  typedef Dimensions2<std::uint32_t> Dimensions2u;
	typedef Dimensions2<std::int64_t> Dimensions2l;
	typedef Dimensions2<std::uint64_t> Dimensions2ul;
  typedef Dimensions2<float> Dimensions2f;
  typedef Dimensions2<double> Dimensions2d;
}

#endif
