/*
 * Unoptimized bubble sort performs the following steps to sort an array
 * from smallest to largest:
 *
 * A) Compare array element 0 with array element 1. If element 0 is larger,
 * swap it with element 1.
 * B) Now do the same for elements 1 and 2, and every subsequent pair of
 * elements until you hit the end of the array. At this point the last
 * element in the array will be sorted.
 * C) Repeat the first two steps again until the array is sorted.
 *
 * Write code that bubble sorts the following array according to the rules
 * above:
 *
 * 	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
 *
 * Print the sorted array elements at the end of your program.
*/
#include <iostream>
#include <utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr std::size_t array_size{ sizeof(array) / sizeof(array[0]) };

	// Note: Unoptimized bubble sort
	for (std::size_t iteration_num{ 0 }; iteration_num < array_size - 1 ; iteration_num++)
	{
		// Bubble values from the beginning of the array to the end
		// of the array
		for (std::size_t i{ 0 }; i < array_size - 1; i++)
		{
			// Nudge the larger value up if it isn't in the higher
			// index already
			if (array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
			}
		}
	}

	// Print out the now sorted array
	for (std::size_t i{ 0 }; i < array_size; i++)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';

	return 0;
}
