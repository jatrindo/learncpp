/*
 * a) Write a simple class named Point3d. The class should contain:
 *
 * 	- Three private member variables of type int named m_x, m_y, m_z
 * 	- A public member function named setValues() that allows you to set
 * 	values for m_x, m_y, and m_z
 * 	- A public member function named print() that prints the Point in the
 * 	following format: <m_x, m_y, m_z>
 *
 * Make sure the following main function executes correctly. This should print:
 *
 * 	<1, 2, 3>
 *
 * b) Add a function named isEqual() to your Point3d class. The following
 * (upadted main()) code should run correctly.
*/
#include <iostream>

class Point3d
{
	int m_x{};
	int m_y{};
	int m_z{};

public:
	void setValues(int x, int y, int z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print()
	{
		std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
	}

	bool isEqual(Point3d& point)
	{
		return (point.m_x == m_x && point.m_y == m_y && point.m_z == m_z);
	}
};

int main()
{
	// Code for part a)
	/*
	Point3d point;
	point.setValues(1, 2, 3);

	point.print();
	std::cout << '\n';
	*/

	// Code for part b)
	Point3d point1;
	point1.setValues(1, 2, 3);

	Point3d point2;
	point2.setValues(1, 2, 3);

	if (point1.isEqual(point2))
	{
		std::cout << "point1 and point2 are equal\n";
	}
	else
	{
		std::cout << "point1 and point2 are not equal\n";
	}

	Point3d point3;
	point3.setValues(3, 4, 5);

	if (point1.isEqual(point3))
	{
		std::cout << "point1 and point3 are equal\n";
	}
	else
	{
		std::cout << "point1 and point3 are not equal\n";
	}

	return 0;
}
