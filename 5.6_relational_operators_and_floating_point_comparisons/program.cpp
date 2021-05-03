#include "float_approx_equals.h"

#include <iostream>

int main()
{
	// a is really close to 1.0 but has rounding errors
	double a { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

	// Compare 'almost 1.0' to 1.0
	std::cout << approxEqualAbsRel(a, 1.0, 1e-12, 1e-8) << '\n';
	// Compare 'almost 0.0' to 0.0
	std::cout << approxEqualAbsRel(a-1.0, 0.0, 1e-12, 1e-8) << '\n';

	return 0;
}
