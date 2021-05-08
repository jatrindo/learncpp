/*
 * Write a file named constants.h that makes the following program run.
 *
 * If your compiler is C++17 capable, use inline constexpr variables.
 * Otherwise, use normal constexpr variables. Pick any value you like
 * for max_class_size.
*/
#include "constants.h"

#include <iostream>

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;

		if (students > constants::max_class_size)
			std::cout << "There are too many students in this class";
		else
			std::cout << "This class isn't too large";

	return 0;
}
