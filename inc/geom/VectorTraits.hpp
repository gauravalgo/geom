
#ifndef GEOM_VECTOR_TRAITS_HPP
#define GEOM_VECTOR_TRAITS_HPP

#include <type_traits>

namespace geom {
	template <typename T> struct IsVector : public std::false_type { };
	template <typename T> struct IsVector2 : public std::false_type { };
	template <typename T> struct IsVector3 : public std::false_type { };
	template <typename T> struct IsVector4 : public std::false_type { };
	
	template <typename T>
	struct VectorType {
		typedef T type;
	};
	
	template <typename LType, typename RType>
	struct VectorOpResult {
		typedef typename std::common_type<typename VectorType<LType>::type,
																			typename VectorType<RType>::type>::type
		type;
	};
}

#endif
