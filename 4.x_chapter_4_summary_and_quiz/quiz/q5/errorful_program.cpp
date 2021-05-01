/*
 * Find 3 issues (affecting 4 lines) in the following code
*/
#include <cstdint>
#include <iostream>

int main()
{
	std::cout << "How old are you?\n";

	std::uint8_t age{};
	std::cin >> age;

	std::cout << "Allowed to drive a car in Texas [";

	if (age >= 16) 
		std::cout << "x";
	else
		std::cout << " ";

	std::cout << "]\n";

	return 0;
}
