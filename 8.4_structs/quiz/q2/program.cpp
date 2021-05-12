/*
 * Create a struct to hold a fraction.
 *
 * The struct should have an integer numerator and an integer denominator
 * member. Declare 2 fraction variables and read them in from the user. 
 *
 * Write a function called multiply that takes both fractions, multiplies
 * them together, and returns the result as a decimal number. You do not need
 * to reduce the fraction to its lowest terms.
 *
 * Print the result of the multiplication of the 2 fraction variables.
*/
#include <iostream>

struct Fraction
{
	int numerator{};
	int denominator{};
};

Fraction askFraction()
{
	Fraction frac{};

	std::cout << "Enter numerator: ";
	std::cin >> frac.numerator;
	std::cout << "Enter denominator: ";
	std::cin >> frac.denominator;

	return frac;
}

double multiply(Fraction frac1, Fraction frac2)
{
	return (static_cast<float>(frac1.numerator) * frac2.numerator)
		/ (static_cast<float>(frac1.denominator) * frac2.denominator);
}

int main()
{
	Fraction frac1{ askFraction() };
	Fraction frac2{ askFraction() };

	std::cout << "The result of multiplying them together is: "
		  << multiply(frac1, frac2) << '\n';

	return 0;
}
