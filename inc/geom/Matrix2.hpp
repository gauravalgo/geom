
#ifndef GEOM_MATRIX_2_HPP
#define GEOM_MATRIX_2_HPP

namespace geom {
  template <typename Scalar>
  struct Matrix2 {
    Matrix2() :
      values{0,0,0,0,0,0,0,0,0}
    { }
    Matrix2(Scalar r1c1, Scalar r1c2, Scalar r1c3,
	    Scalar r2c1, Scalar r2c2, Scalar r2c3,
	    Scalar r3c1, Scalar r3c2, Scalar r3c3) :
      values{r1c1, r2c1, r3c1, r1c2, r2c2, r3c2, r1c3, r2c3, r3c3}
    { }
    Matrix2(const Matrix2<Scalar> &source) :
      values{source.values[0], source.values[1], source.values[2],
	source.values[3], source.values[4], source.values[5],
	source.values[6], source.values[7], source.values[8]}
    { }
    
    template <typename Other>
    Matrix2(const Matrix2<Other> &source) :
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
    
    ~Matrix2() = default;
    
    Matrix2<Scalar> & operator=(const Matrix2<Scalar> &source) {
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
    template <typename Other>
    Matrix2<Scalar> & operator=(const Matrix2<Other> &source) {
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
    
    Scalar values[9];
  };
  
  typedef Matrix2<std::int32_t> Matrix2i;
  typedef Matrix2<std::uint32_t> Matrix2u;
  typedef Matrix2<float> Matrix2f;
  typedef Matrix2<double> Matrix2d;
}

#endif
