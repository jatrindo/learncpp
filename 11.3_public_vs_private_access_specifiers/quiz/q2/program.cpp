/*
 * Write a simple class named Point3d. The class should contain:
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
};

int main()
{
	Point3d point;
	point.setValues(1, 2, 3);

	point.print();
	std::cout << '\n';

	return 0;
}
