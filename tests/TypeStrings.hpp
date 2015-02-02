
#ifndef GEOM_TESTING_TYPE_STRINGS_HPP
#define GEOM_TESTING_TYPE_STRINGS_HPP

#include <stdint.h>

namespace geom {
	template <typename T>
	const char * TypeString() { return "Unknown"; }
	
	template <>
	const char * TypeString<double>() { return "double"; }
	
	template <>
	const char * TypeString<float>() { return "float"; }
}

#endif
