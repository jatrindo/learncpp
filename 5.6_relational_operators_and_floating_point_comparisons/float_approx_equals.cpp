#include "float_approx_equals.h"

#include <algorithm>
#include <iostream>
#include <cmath>

bool approxEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	// Check if the numbers are really close -- needed when comparing
	// numbers near zero
	double diff{ std::abs(a-b) };
	if (diff <= absEpsilon)
		return true;

	// Otherwise fall back to Knuth's algorithm (which breaks down near
	// zero, hence the previous check)
	return (diff <=(std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
