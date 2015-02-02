
/**
 * \file Matrix2.hpp
 * \author Troy Varney <troy.a.varney@gmail.com>
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

#ifndef GEOM_MATRIX_3_HPP
#define GEOM_MATRIX_3_HPP

namespace geom {
  /**
   * \brief A Matrix used to manipulate 2 dimensional geometry.
   * 
   * The values of the matrix are stored in column major order to match the
   * format that OpenGL stores matricies in.
   */
  template <typename Scalar>
  struct Matrix2 {
    /**
     * \brief Construct a null \c Matrix2 object
     * 
     * This matrix will zero any other matrix multiplied by it. That is,
     * given \c Matrix2 A and \c Matrix2 B where A is null, A*B = [0...]
     */
    Matrix2() :
      values{0,0,0,0}
    { }
    /**
     * \brief Construct a \c Matrix2 object with the given values.
     * 
     * The values passed into this constructor are expected in
     * row-major order and are then shuffled into column-major order in the
     * initializer list. This is done because matrices are more intuitively
     * described in row-major order, yet the internal ordering is column major.
     */
    Matrix2(Scalar r1c1, Scalar r1c2, Scalar r2c1, Scalar r2c2) :
			values{r1c1, r2c1, r1c2, r2c2}
    { }
    /**
     * \brief Construct a \c Matrix2 object which is a copy of the given
     * \c Matrix2 object.
     * \arg \c source The \c Matrix2 object to copy
     */
    Matrix2(const Matrix2<Scalar> &source) :
      values{source.values[0], source.values[1], source.values[2],
				source.values[3]}
    { }
    
    /**
     * \brief Construct a \c Matrix2 object which is a conversion of the given
     * \c Matrix2 object.
     * \arg \c source The \c Matrix2 object to copy
     */
    template <typename Other>
    Matrix2(const Matrix2<Other> &source) :
      values{static_cast<Scalar>(source.values[0]),
				static_cast<Scalar>(source.values[1]),
				static_cast<Scalar>(source.values[2]),
				static_cast<Scalar>(source.values[3])}
    { }
    
    ~Matrix2() = default;
    
    /**
     * \brief Assign values from the given \c Matrix2 object.
     * \arg \c source The \c Matrix2 to assign values from
     * \return A reference to the \c Matrix2 object being assigned to
     */
    Matrix2<Scalar> & operator=(const Matrix2<Scalar> &source) {
      values[0] = source.values[0];
      values[1] = source.values[1];
      values[2] = source.values[2];
      values[3] = source.values[3];
      return *this;
    }
    /**
     * \brief Assign converted values from the given \c Matrix2 object.
     * \arg \c source The \c Matrix2 to assign converted values from
     * \return A reference to the \c Matrix2 object being assigned to
     */
    template <typename Other>
    Matrix2<Scalar> & operator=(const Matrix2<Other> &source) {
      values[0] = static_cast<Scalar>(source.values[0]);
      values[1] = static_cast<Scalar>(source.values[1]);
      values[2] = static_cast<Scalar>(source.values[2]);
      values[3] = static_cast<Scalar>(source.values[3]);
      return *this;
    }
    
    /**
     * \brief The array of values stored in the matrix.
     * 
     * The values are stored in column-major value inside the array. To index
     * a value in the matrix of the form [i][j] the index would be
     * \f$i*2+j\f$.
     */
    Scalar values[4];
  };
  
  typedef Matrix2<std::int32_t> Matrix2i;
  typedef Matrix2<std::uint32_t> Matrix2u;
  typedef Matrix2<float> Matrix2f;
  typedef Matrix2<double> Matrix2d;
}

#endif
