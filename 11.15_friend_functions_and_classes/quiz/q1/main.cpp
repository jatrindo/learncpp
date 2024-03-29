/*
 * In geometry a point is a position in space. We can define a point in 3d-space
 * as the set of coordinates x, y, z.
 *
 * In physics, vector is a quantity that has a magnitude (length) and a
 * direction (but not position). We can define a vector in 3d-space as an x, y,
 * and z value representing the direction of the vector along the x, y, and z
 * axis (the length can be derived from there). For example, the Vector(2.0,
 * 0.0, 0.0) would be a vector representing a direction across the positive
 * x-axis (only), with length 2.0.
 *
 * A Vector can be applied to a Point to move the Point to a new position. This
 * is done by adding the vector's direction to the point's position to yield a
 * new position. For example, Point(2.0, 1.0, 0.0) + Vector(2.0, 0.0, 0.0) would
 * yield the point (4.0, 1.0, 0.0).
 *
 * Points and Vectors are often used in computer graphics (the point to
 * represent verticies of shape, and vectors represent movement of the shape).
 * 
 * Given the following program,
 *
 * 1a) Make Point3d a friend class of Vector3d, and implement function
 * Point3d::moveByVector()
 *
 * 1b) Instread of making class Point3d a friend of class Vector 3d, make member
 * function Point3d::moveByVector a friend of class Vector3d
 *
 * 1c) Reimplement the solution to quiz question 1b) using 5 separate files:
 * Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp.
*/

#include "Point3d.h"
#include "Vector3d.h"

int main()
{
	Point3d p{ 1.0, 2.0, 3.0 };
	Vector3d v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}

