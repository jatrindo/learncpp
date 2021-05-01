/*
 * Find 3 issues (affecting 4 lines) in the following code
*/
#include <cstdint>
#include <iostream>

int main()
{
	std::cout << "How old are you?\n";

	std::uint8_t age{}; // Error 1
	std::cin >> age;

	std::cout << "Allowed to drive a car in Texas [";

	if (age >= 16) // Error 3
		std::cout << "x"; // Error 2, pt 1
	else
		std::cout << " "; // Error 2, pt 2

	std::cout << "]\n";

	return 0;
}

/*
 * Explanations:
 *
 * Error 1:
 * 	- std::uint8_t is an optional type; not all systems support it
 * 	- If we were to print 'age' it would be treated as a character by std::cout
 * 	- A regular 'int' should be used to store the age. Age doesn't require a specific
 * 		minimum integer width
 *
 * Error 2, pt 1 & 2:
 * 	- The characters 'x' and ' ' should be in single quotes, rather than double quotes
 * 		- Double-quoting 'x' and ' ' requires more storage and cause slower
 * 		functions to be called than if we used single quotation marks
 *
 * Error 3:
 * 	- '16' can be seen as a magic number
 * 		- As per best practice, a constexpr variable with the value 16 should be
 * 		defined and used instead
*/
