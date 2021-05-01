/*
 * Find 3 issues (affecting 4 lines) in the following code
*/
#include <cstdint>
#include <iostream>

int main()
{
	std::cout << "How old are you?\n";

	std::uint8_t age{}; // Error 1: No need (+ risky) to use an _unsigned_ int (and an 8b one at that)
	std::cin >> age; // Error 2: Use of *int8_t is a problem since it will be interpreted as a character

	std::cout << "Allowed to drive a car in Texas [";

	if (age >= 16) // Error 3: The interpretation of age as a character means that the decimal value of the corresponding ASCII character will be compared against 16
		std::cout << "x";
	else
		std::cout << " ";

	std::cout << "]\n";

	return 0;
}
