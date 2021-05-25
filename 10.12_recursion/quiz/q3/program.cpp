/*
 * 3a) Write a program that asks the user to enter a positive integer, and then
 * uses a recursive function to print out the binary representation for that
 * number. Use method 1 from lesson O.4 -- Converting between binary and
 * decimal.
 *
 * 3b) Update your code from 3a) to handle the case where the user may enter 0
 * or a negative number.
 *
 * Here's a sample output (assuming 32-bit integers):
 *
 * Enter an integer: -15
 * 11111111111111111111111111110001
 *
*/
#include <iostream>

// Prints the binary representation of i
void printBinRep(unsigned int i)
{
	// Base case (when i == 0, we stop recursing but still print
	if (i > 1)
		printBinRep(i / 2); // Recurse

	// Print the remainder
	std::cout << (i % 2);
}

int askInteger()
{
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;

	return i;
}

int main()
{
	int i{ askInteger() };
	std::cout << "The binary representation of " << i << " is ";
	printBinRep(static_cast<unsigned int>(i));
	std::cout << '\n';

	return 0;
}
