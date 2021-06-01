/*
 * Update the following program to use non-static member initialization and
 * member initializer lists.
 *
 * This program should produce the result:
 *
 * 	color: black, radius: 10
 * 	color: blue, radius: 10
 * 	color: black, radius: 20
 * 	color: blue, radius: 20
*/
#include <string>
#include <iostream>

class Ball
{
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:
	// Constructor with only radius parameter (color will use default value)
	Ball(double radius)
		: m_radius{ radius }
	{
	}

	// Constructor with both color and radius parameters
	Ball(const std::string& color="black", double radius=10.0)
		: m_color{ color }, m_radius{ radius }
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}
