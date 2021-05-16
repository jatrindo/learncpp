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
#include <string>
#include <string_view>

int main()
{
	constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily",
		"Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string name_query{};
	std::cin >> name_query;

	bool found{ false };

	for (const std::string_view name : names)
	{
		if (name == name_query)
		{
			found = true;
			break;
		}
	}

	if (found)
		std::cout << name_query << " was found.\n";
	else
		std::cout << name_query << " was not found.\n";

	return 0;
}
