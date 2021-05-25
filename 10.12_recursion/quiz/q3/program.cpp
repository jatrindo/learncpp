/*
 * Write a program tat asks the user to enter a positive integer, and then
 * uses a recursive function to print out the binary representation for that
 * number. Use method 1 from lesson O.4 -- Converting between binary and
 * decimal.
*/
#include <iostream>

// Prints the binary representation of i
void printBinRep(int i)
{
	// Base case
	if (i == 0)
		return;

	// Recurse first
	printBinRep(i / 2);

	// Print the remainder
	std::cout << (i % 2);
}

int askInteger()
{
	std::cout << "Enter a positive integer: ";
	int i{};
	std::cin >> i;

	if (i < 0)
	{
		std::cout << "Value entered was negative. Flipping the sign\n";
		i = -i;
	}

	return i;
}

int main()
{
	int i{ askInteger() };
	std::cout << "The binary representation of " << i << " is ";
	printBinRep(i);
	std::cout << '\n';

	return 0;
}
