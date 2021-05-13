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

	// Strategy:
	//
	// On each passthrough of the array, bubble sort manages to move the
	// largest value in the array to the last index, where it belongs.
	//
	// When that happens, only the 0th to size-2 elements remain unsorted,
	// meaning that we only have to bubble through the [0, size-2] range,
	// rather than all of [0, size-1].
	//
	// Thus with each passthrough of array, the last index of the unsorted
	// portion of the array decreases by 1
	//
	// Once the last unsorted index of the array is 0, we stop since there
	// are no longer any more elements to swap

	// Initially, the whole array is unsorted, meaning that the last index
	// of the unsorted portion of the array is exactly the last index of
	// the array
	for (std::size_t last_unsorted_index{ array_size - 1 }; last_unsorted_index > 0; last_unsorted_index--)
	{
		// Bubble from the beginning to the last index of the unsorted
		// portion of the array
		for (std::size_t i{ 0 }; i <= last_unsorted_index; i++)
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
