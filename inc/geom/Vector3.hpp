
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
#include <cmath>

#include "VectorTraits.hpp"

namespace geom {
  /**
   * \brief A templated 3 dimensional vector structure
   */
  template <typename Scalar>
  struct Vector3 {
		typedef Scalar type;
		
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
		 * \brief Vector negation
		 * \return A new \c Vector3 object which is the negation of this \c Vector3
		 */
		Vector3<Scalar> operator-() {
			return Vector3<Scalar>(-x,-y,-z);
		}
		
    /**
     * \brief Assign the result of adding two vectors.
     * \arg \c rhs The vector to add to this \c Vector3 object
     * \return A reference to the \c Vector3 object being assigned to
     */
		template <typename RhsType>
    Vector3<Scalar> & operator+=(const Vector3<RhsType> &rhs) {
      return *this = *this + rhs;
    }
		
    /**
     * \brief Assign the result of subtracting two vectors.
     * \arg \c rhs The vector to subtract from this \c Vector3 object
     * \return A reference to the \c Vector3 object being assigned to
     */
		template <typename RhsType>
		Vector3<Scalar> & operator-=(const Vector3<RhsType> &rhs) {
			return *this = *this - rhs;
		}
		
    /**
     * \brief Assign the result of scalar multiplication
     * \arg \c rhs The scalar to multiply this vector by.
     * \return A reference to the \c Vector3 object being assigned to
     */
		template <typename RhsType>
		Vector3<Scalar> & operator*=(const RhsType &rhs) {
			return *this = *this * rhs;
		}
		
    /**
     * \brief Assign the result of scalar division
     * \arg \c rhs The scalar to divide this vector by
     * \return A reference to the \c Vector3 object being assigned to
     */
		template <typename RhsType>
		Vector3<Scalar> & operator/=(const RhsType &rhs) {
			return *this = *this / rhs;
		}
    
    Scalar x; /**< The x component of the \c Vector3 object */
    Scalar y; /**< The y component of the \c Vector3 object */
    Scalar z; /**< The z component of the \c Vector3 object */
  };
  
  typedef Vector3<std::int32_t> Vec3i;
  typedef Vector3<std::uint32_t> Vec3u;
  typedef Vector3<std::int64_t> Vec3l;
  typedef Vector3<std::uint64_t> Vec3ul;
  typedef Vector3<float> Vec3f;
  typedef Vector3<double> Vec3d;
  
	/**
	 * \breif Test vectors component-wise for equality.
	 * \arg \c lhs The vector on the left of the equality operator.
	 * \arg \c rhs The vector on the right of the equality operator.
	 * \return True if all elements are equal, false otherwise.
	 */
	template <typename LType, typename RType>
	bool operator==(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
	}
	
	/**
	 * \breif Test if two vectors are not equal.
	 * \arg \c lhs The vector on the left of the inequality operator.
	 * \arg \c rhs The vector on the right of the inequality operator.
	 * \return True if any element is different, False otherwise.
	 */
	template <typename LType, typename RType>
	bool operator!=(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return !(lhs == rhs);
	}
	
	/**
	 * \breif Test vectors component-wise for being less than.
	 * \arg \c lhs The vector on the left of the less than operator.
	 * \arg \c rhs The vector on the right of the less than operator.
	 * \return True if all elements in lhs are smaller than the corresponding
	 * element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator<(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return (lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z);
	}
	
	/**
	 * \brief Test vectors component-wise for being less than or equal.
	 * \arg \c lhs The vector on the left of the less than or equal operator.
	 * \arg \c rhs The vector on the right of the less than or equal operator.
	 * \return True if all elements in lhs are smaller than or equal to the
	 * corresponding element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator<=(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return (lhs.x <= rhs.x && lhs.y <= rhs.y && lhs.z <= rhs.z);
	}
	
	/**
	 * \brief Test vectors component-wise for being greater than.
	 * \arg \c lhs The vector on the left of the greater than operator.
	 * \arg \c rhs The vector on the right of the greater than operator.
	 * \return True if all elements in lhs are larger than the corresponding
	 * element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator>(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return (lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z);
	}
	
	/**
	 * \brief Test vectors component-wise for being greater than or equal.
	 * \arg \c lhs The vector on the left of the greater than or equal operator.
	 * \arg \c rhs The vector on the right of the greater than or equal operator.
	 * \return True if all elements in lhs are larger than or equal to the
	 * corresponding element in rhs.
	 */
	template <typename LType, typename RType>
	bool operator>=(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return (lhs.x >= rhs.x && lhs.y >= rhs.y && lhs.z >= rhs.z);
	}
	
  /**
   * \brief Add two \c Vector3 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the expression
   * \arg \c rhs The operand on the right hand side of the expression
   * \return A new \c Vector3 object that contains the result of adding lhs and
   * rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator+(const Vector3<LhsType> &lhs,
														const Vector3<RhsType> &rhs)
  {
    return Vector3<Result>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
  }
	
	  /**
   * \brief Subtract two \c Vector3 objects and return the result.
   * \arg \c lhs The operand on the left hand side of the expression
   * \arg \c rhs The operand on the right hand side of the expression
   * \return A new \c Vector3 object that contains the result of subtracting
   * rhs from lhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator-(const Vector3<LhsType> &lhs,
														const Vector3<RhsType> &rhs)
  {
    return Vector3<Result>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
  }
	
  /**
   * \brief Multiply two \c Vector3 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the expression
   * \arg \c rhs The operand on the right hand side of the expression
   * \return A new \c Vector3 object that contains the result of multiplying
	 * lhs and rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator*(const Vector3<LhsType> &lhs,
														const Vector3<RhsType> &rhs)
  {
    return Vector3<Result>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
  }
	
  /**
   * \brief Multiply a \c Vector3 object by a scalar.
   * \arg \c lhs The \c Vector3 object to multiply
   * \arg \c rhs The scalar to multiply the \c Vector3 object by
   * \return A new \c Vector3 object that contains the result of multiplying
	 * lhs by rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator*(const Vector3<LhsType> &lhs, const RhsType &rhs)
  {
		static_assert(!IsVector<RhsType>::value,
									"Multiplication is not defined for the given types");
    return Vector3<Result>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
  }
	
  /**
   * \brief Multiply a \c Vector3 object by a scalar.
   * \arg \c lhs The scalar to multiply the \c Vector3 object by
   * \arg \c rhs The \c Vector3 object to multiply
   * \return A new \c Vector3 object that contains the result of multiplying
	 * lhs by rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator*(const LhsType &lhs, const Vector3<RhsType> &rhs)
  {
		static_assert(!IsVector<LhsType>::value,
									"Multiplication is not defined for the given types");
    return Vector3<Result>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
  }
	
	/**
   * \brief Divide two \c Vector3 objects together and return the result.
   * \arg \c lhs The operand on the left hand side of the expression
   * \arg \c rhs The operand on the right hand side of the expression
   * \return A new \c Vector3 object that contains the result of dividing lhs
	 * by rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator/(const Vector3<LhsType> &lhs,
														const Vector3<RhsType> &rhs)
  {
    return Vector3<Result>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
  }
	
	/**
   * \brief Divide a \c Vector3 object by a scalar.
   * \arg \c lhs The \c Vector3 object to divide
   * \arg \c rhs The scalar to divide the \c Vector3 object by
   * \return A new \c Vector3 object that contains the result of dividing lhs
	 * by rhs
   */
  template <typename RhsType, typename LhsType,
						typename Result = typename VectorOpResult<RhsType,LhsType>::type>
  Vector3<Result> operator/(const Vector3<LhsType> &lhs, const RhsType &rhs)
  {
		static_assert(!IsVector<RhsType>::value,
									"Division is not defined for the given types");
    return Vector3<Result>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
  }
	
	/**
	 * \brief Get the length of the vector.
	 * 
	 * Any type vector which isn't a float or double vector is first converted to
	 * a double vector.
	 * 
	 * \arg \c v The vector to get the length of.
	 * return The length of the vector.
	 */
	template <typename Scalar>
	double length(const Vector3<Scalar> &v) {
		return std::sqrt((double)(v.x * v.x + v.y * v.y + v.z * v.z));
	}
	inline float length(const Vector3<float> &f) {
		return std::sqrt(f.x * f.x + f.y * f.y + f.z * f.z);
	}
	
	/**
	 * \brief Calculat the dot product between two vectors.
	 * \arg \c lhs The \c Vector3 object on the left side of the dot operation.
	 * \arg \c rhs The \c Vector3 object on the right side of the dot operation.
	 * \return The result of the dot product of the two \c Vector3 objects.
	 */
	template <typename RType, typename LType,
						typename Result = typename VectorOpResult<LType,RType>::type>
	Result dot(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}
	
	/**
	 * \brief Calculate the cross product bewteen two vectors.
	 * \arg \c lhs The \c Vector3 object on the left side of the cross product.
	 * \arg \c rhs The \c Vector3 object on the right side of the cross product.
	 * \return The \c Vector3 object which is the result of the cross product.
	 */
	template <typename RType, typename LType,
						typename Result = typename VectorOpResult<LType,RType>::type>
	Vector3<Result> cross(const Vector3<LType> &lhs, const Vector3<RType> &rhs) {
		return Vector3<Result>(lhs.y * rhs.z - lhs.z * rhs.y,
													 lhs.z * rhs.x - lhs.x * rhs.z,
													 lhs.x * rhs.y - lhs.y * rhs.x);
	}
	
	/**
	 * \brief Reflect the given vector around the given normal.
	 * 
	 * \given reflect(i,n), the reflection is calculated as
	 * \f$ i - 2 * (i \cdot n) * n \f$
	 * 
	 * It is important that the normal vector is normalized before this
	 * operation.
	 * 
	 * \arg \c vec The vector to reflect.
	 * \arg \c normal The normal vector of the surface reflecting the vector.
	 * \return A new \c Vector3 object that is the reflection about the normal.
	 */
	template <typename RType, typename LType,
						typename Result = typename VectorOpResult<LType,RType>::type>
	Vector3<Result> reflect(const Vector3<LType> &vec,
													const Vector3<RType> &normal)
	{
		return vec - ((2 * dot(vec, normal)) * normal);
	}
	
	/**
	 * \brief Normalize the \c Vector3 object.
	 * 
	 * The resulting vector will have a length of 1.0
	 * 
	 * The resulting vector defaults to type double unless the type of the input
	 * vector is a float.
	 * 
	 * \arg \c vec The \c Vector3 object to normalize.
	 * \return A new \c Vector3 object which is normalized.
	 */
	template <typename IntegralType, typename RType = double>
	Vector3<RType> normalize(const Vector3<IntegralType> &source) {
		return source / length(source);
	}
	inline Vector3<float> normalize(const Vector3<float> &source) {
		return source / length(source);
	}
	
	/**
	 * \brief Calculate refracted vector.
	 * 
	 * The refracted index is calculated by finding the value
	 * \f$k = 1 - e * e * (1 - (n \cdot i)^2)\f$
	 * and if it is negative returning a null vector, otherwise returning the
	 * vector \f$e * i - (e * (n \cdot i) + k^0.5) * n\f$
	 * 
	 * This function will cause a compile error if the index of refraction is
	 * not a floating point type. To allow this function to work with custom
	 * types that express proper floating point semantics, override the standard
	 * structure \c std::is_floating_point for your type to be \c std::true_type
	 * 
	 * The return type is the common type between the vector types and the index
	 * type.
	 * 
	 * \arg \c i The incident vector.
	 * \arg \c n The normal vector of the refracting surface.
	 * \arg \c eta The index of refraction of the refracting surface.
	 * \return The refracted \c Vector2 object
	 */
	template <typename VType1, typename VType2, typename FType,
						typename R = typename std::common_type<FType,VType1,VType2>::type>
	Vector3<R> refract(const Vector3<VType1> &i, const Vector3<VType2> &n,
										 const FType &eta)
	{
		static_assert(std::is_floating_point<FType>::value,
									"The type of a refraction index must be floating point");
		
		R dot_ni = dot(n, i);
		R k = 1.0 - eta * eta * (1.0 - dot_ni * dot_ni);
		if(k < 0.0) {
			return Vector3<R>(0.0, 0.0);
		}else {
			return (eta * i - (eta * dot_ni + std::sqrt(k)) * n);
		}
	}
	
	template <typename T>
	struct IsVector<Vector3<T>> : public std::true_type { };
	template <typename T>
	struct IsVector3<Vector3<T>> : public std::true_type { };
	
	template <typename T>
	struct VectorType<Vector3<T>> {
		typedef T type;
	};
}

#endif
