/*
 * Declare a fixed array with the following names: Alex, Betty, Caroline, Dave,
 * Emily, Fred, Greg, and Holly.
 *
 * Ask the user to enter a name. Use a for each loop to see if the name the
 * user entered is in the array.
 *
 * Sample output:
 *
 * 	Enter a name: Betty
 * 	Betty was found.
 *
 *
 * 	Enter a name: Megatron
 * 	Megatron was not found.
*/
#include <iostream>

int main()
{
	std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily",
		"Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string name_query{};
	std::cin >> name_query;

	for (const std::string_view name : names)
	{
		if (name == name_query)
		{
			std::cout << name_query << " was found.\n";
			return 0;
		}
	}

	std::cout << name_query << " was not found.\n";

	return 0;
}
