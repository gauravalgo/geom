
/**
 * \file Matrix3.hpp
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
  struct Matrix3 {
    /**
     * \brief Construct a null \c Matrix3 object
     * 
     * This matrix will zero any other matrix multiplied by it. That is,
     * given \c Matrix3 A and \c Matrix3 B where A is null, A*B = [0...]
     */
    Matrix3() :
      values{0,0,0,0,0,0,0,0,0}
    { }
    /**
     * \brief Construct a \c Matrix3 object with the given values.
     * 
     * The values passed into this constructor are expected in
     * row-major order and are then shuffled into column-major order in the
     * initializer list. This is done because matrices are more intuitively
     * described in row-major order, yet the internal ordering is column major.
     */
    Matrix3(Scalar r1c1, Scalar r1c2, Scalar r1c3,
	    Scalar r2c1, Scalar r2c2, Scalar r2c3,
	    Scalar r3c1, Scalar r3c2, Scalar r3c3) :
      values{r1c1, r2c1, r3c1, r1c2, r2c2, r3c2, r1c3, r2c3, r3c3}
    { }
    /**
     * \brief Construct a \c Matrix3 object which is a copy of the given
     * \c Matrix3 object.
     * \arg \c source The \c Matrix3 object to copy
     */
    Matrix3(const Matrix3<Scalar> &source) :
      values{source.values[0], source.values[1], source.values[2],
	source.values[3], source.values[4], source.values[5],
	source.values[6], source.values[7], source.values[8]}
    { }
    
    /**
     * \brief Construct a \c Matrix3 object which is a conversion of the given
     * \c Matrix3 object.
     * \arg \c source The \c Matrix3 object to copy
     */
    template <typename Other>
    Matrix3(const Matrix3<Other> &source) :
      values{static_cast<Scalar>(source.values[0]),
	static_cast<Scalar>(source.values[1]),
	static_cast<Scalar>(source.values[2]),
	static_cast<Scalar>(source.values[3]),
	static_cast<Scalar>(source.values[4]),
	static_cast<Scalar>(source.values[5]),
	static_cast<Scalar>(source.values[6]),
	static_cast<Scalar>(source.values[7]),
	static_cast<Scalar>(source.values[8])}
    { }
    
    ~Matrix3() = default;
    
    /**
     * \brief Assign values from the given \c Matrix3 object.
     * \arg \c source The \c Matrix3 to assign values from
     * \return A reference to the \c Matrix3 object being assigned to
     */
    Matrix3<Scalar> & operator=(const Matrix3<Scalar> &source) {
      values[0] = source.values[0];
      values[1] = source.values[1];
      values[2] = source.values[2];
      values[3] = source.values[3];
      values[4] = source.values[4];
      values[5] = source.values[5];
      values[6] = source.values[6];
      values[7] = source.values[7];
      values[8] = source.values[8];
      return *this;
    }
    /**
     * \brief Assign converted values from the given \c Matrix3 object.
     * \arg \c source The \c Matrix3 to assign converted values from
     * \return A reference to the \c Matrix3 object being assigned to
     */
    template <typename Other>
    Matrix3<Scalar> & operator=(const Matrix3<Other> &source) {
      values[0] = static_cast<Scalar>(source.values[0]);
      values[1] = static_cast<Scalar>(source.values[1]);
      values[2] = static_cast<Scalar>(source.values[2]);
      values[3] = static_cast<Scalar>(source.values[3]);
      values[4] = static_cast<Scalar>(source.values[4]);
      values[5] = static_cast<Scalar>(source.values[5]);
      values[6] = static_cast<Scalar>(source.values[6]);
      values[7] = static_cast<Scalar>(source.values[7]);
      values[8] = static_cast<Scalar>(source.values[8]);
      return *this;
    }
    
    /**
     * \brief The array of values stored in the matrix.
     * 
     * The values are stored in column-major value inside the array. To index
     * a value in the matrix of the form [i][j] the index would be
     * \f$i*3+j\f$.
     */
    Scalar values[9];
  };
  
  typedef Matrix3<std::int32_t> Matrix3i;
  typedef Matrix3<std::uint32_t> Matrix3u;
  typedef Matrix3<float> Matrix3f;
  typedef Matrix3<double> Matrix3d;
}

#endif
