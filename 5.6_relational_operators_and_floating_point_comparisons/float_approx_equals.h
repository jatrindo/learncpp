#ifndef FLOAT_APPROX_EQUALS_H
#define FLOAT_APPROX_EQUALS_H

// Compares two floats for equality, returning true if either:
// 	- they are within an absolute epsilon difference of eachother,
// 	- or, failing that, are within an epsilon difference whose value
// 	is calculated a percentage of the larger magnitude value between
// 	a and b
bool approxEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

#endif // FLOAT_APPROX_EQUALS_H
