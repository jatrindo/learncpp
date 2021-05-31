/*
 * a) Write a class named Ball. Ball should have two private member variables
 * with default values: m_color ("black") and m_radius (10.0).
 *
 * Ball should provide constructors to set only m_color, set only m_radius, set
 * both, or set neither value.
 *
 * For this quiz question, do not use default parameters for your constructors.
 * Also write a function to print out the color and radius of the ball.
 *
 * The following sample program (main()) should compile.
 *
 * b) Update your answer to the previous question to use constructors with
 * default parameters. Use as few constructors as possible.
*/
#include <iostream>

class Ball
{
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:
	Ball() = default;

	Ball(std::string color)
	{
		m_color = color;
	}

	Ball(double radius)
	{
		m_radius = radius;
	}

	Ball(std::string color, double radius)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		std::cout << "color: " << m_color
			  << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}
