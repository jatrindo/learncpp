/*
 * Print the following array to the screen using a loop:
 * 	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
*/
#include <iostream>

int main()
{
  	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	int array_size{ sizeof(array) / sizeof(array[0]) };

	for (int i{ 0 }; i < array_size; i++)
		std::cout << array[i] << ' ';

	std::cout << '\n';

	return 0;
}
