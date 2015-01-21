
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
    
		/**
		 * \breif Get a negated copy of this vector.
		 * \return A new \c Vector2 object with components multiplied by -1
		 */
		Vector2<Scalar> operator-() {
			return Vector2<Scalar>(-x, -y);
		}
		
    /**
     * \brief Assign the result of adding two vectors.
     * \arg \c rhs The vector to add to this \c Vector2 object
     * \return A reference to the \c Vector2 object being assigned to
     */
		template <typename RhsType>
    Vector2<Scalar> & operator+=(const Vector2<RhsType> &rhs) {
      return *this = *this + rhs;
    }
		
		/**
		 * \brief Assign the result of subtracting two vectors.
		 * \arg \c rhs The vector to subtract from this \c Vector2 object
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator-=(const Vector2<RhsType> &rhs) {
			return *this = *this - rhs;
		}
		
		/**
		 * \brief Assign the result of multiplying two vectors.
		 * \arg \c rhs The vector to muliply this \c Vector2 object by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator*=(const Vector2<RhsType> &rhs) {
			return *this = *this * rhs;
		}
		
		/**
		 * \breif Assign the result of dividing two vectors.
		 * \arg \c rhs The vector to divide this \c Vector2 object by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator/=(const Vector2<RhsType> &rhs) {
			return *this = *this / rhs;
		}
		
		/**
		 * \breif Assign the result of multiplying a vector by a scalar.
		 * \arg \c rhs The scalar to multiply this vector by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator*=(const RhsType &rhs) {
			return *this = *this * rhs;
		}
		
		/**
		 * \brief Assign the result of dividing a vector by a scalar.
		 * \arg \c rhs The scalar to divide this vector by
		 * \return A reference to the \c Vector2 object being assigned to
		 */
		template <typename RhsType>
		Vector2<Scalar> & operator/=(const RhsType &rhs) {
			return *this = *this / rhs;
		}
    
    Scalar x; /**< The x component of the \c Vector2 object */
    Scalar y; /**< The y component of the \c Vector2 object */
  };
  
  typedef Vector2<std::int32_t> Vec2i;
  typedef Vector2<std::uint32_t> Vec2u;
  typedef Vector2<float> Vec2f;
  typedef Vector2<double> Vec2d;
  
  /**
   * \brief Add two \c Vector2 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the addition symbol
   * \arg \c rhs The operand on the right hand side of the addition symbol
   * \return A new \c Vector2 object that contains the result of adding lhs and
   * rhs
   */
  template <typename RhsType, typename LhsType,
	    typename Result = typename std::common_type<RhsType,LhsType>::type>
  Vector2<Result> operator+(const Vector2<LhsType> &lhs,
			    const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x + rhs.x, lhs.y + rhs.y);
  }
	
	/**
	 * \breif Subtract two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression.
	 * \arg \c rhs The operand on the right hand side of the expression.
	 * \return A new \c Vector2 object that contains the results of subtracting
	 * rhs from lhs
	 */
  template <typename RhsType, typename LhsType,
            typename Result = typename std::common_type<RhsType,LhsType>::type>
  Vector2<Result> operator-(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x - rhs.x, lhs.y - rhs.y);
  }
  
	/**
	 * \brief Piecewise multiply two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression
	 * \arg \c rhs The operand on the right hand side of the expression
	 * \return A new \c Vector2 object that contains the results of muliplying
	 * lhs by rhs.
	 */
  template <typename RhsType, typename LhsType,
            typename Result = typename std::common_type<RhsType,LhsType>::type>
  Vector2<Result> operator*(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x * rhs.x, lhs.y * rhs.y);
  }
  
	/**
	 * \breif Piecewise divide two \c Vector2 objects and return the result.
	 * \arg \c lhs The operand on the left hand side of the expression
	 * \arg \c rhs The operand on the right hand side of the expression
	 * \return A new \c Vector2 object that contains the results of dividing lhs
	 * by rhs.
	 */
  template <typename RhsType, typename LhsType,
            typename Result = typename std::common_type<RhsType,LhsType>::type>
  Vector2<Result> operator/(const Vector2<LhsType> &lhs,
                            const Vector2<RhsType> &rhs)
  {
    return Vector2<Result>(lhs.x / rhs.x, lhs.y / rhs.y);
  }
	
	/**
	 * \brief Scalar multiplication of a \c Vector2 object.
	 * \arg \c lhs The \c Vector2 object to multiply.
	 * \arg \c rhs The scalar to multiply the \c Vector2 object by.
	 * \return A new \c Vector2 object that is the result of the scalar
	 * multiplication.
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename std::common_type<RhsType,LhsType>::type>
	Vector2<Result> operator*(const Vector2<LhsType> &lhs, const RhsType &rhs)
	{
		return Vector2<Result>(lhs.x * rhs, lhs.y * rhs);
	}
	
	/**
	 * \breif Scalar mulitplication of a \c Vector2 object.
	 * \arg \c lhs The scalar to multiply the \c Vector2 object by.
	 * \arg \c rhs The \c Vector2 object to multiply.
	 * \return A new \c Vector2 object that is the result of the scalar
	 * multiplication.
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename std::common_type<RhsType,LhsType>::type>
	Vector2<Result> operator*(const LhsType &lhs, const Vector2<RhsType> &rhs)
	{
		return Vector2<Result>(rhs.x * lhs, rhs.y * lhs);
	}
	
	/**
	 * \breif Scalar division of a \c Vector2 object.
	 * \arg \c lhs The \c Vector2 object to divide.
	 * \arg \c rhs The scalar to divide the \c Vector2 object by.
	 * \return A new \c Vector2 object that is the result of the scalar division
	 */
	template <typename RhsType, typename LhsType,
						typename Result = typename std::common_type<RhsType,LhsType>::type>
	Vector2<Result> operator/(const Vector2<LhsType> &lhs, const RhsType &rhs)
	{
		return Vector2<Result>(lhs.x / rhs, lhs.y / rhs);
	}
}

#endif
