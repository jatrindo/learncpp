/*
 * Write a function named find that takes a pointer to the beginning and a
 * pointer to the end (1 element past the last) of an array, as well as a
 * value.
 *
 * The function should search for the given value and return a pointer to the
 * first element with that value, or the end pointer if no element was found.
 *
 * The following [code in main] should run.
*/
#include <iostream>
#include <iterator>

int* find(int* start, int* end, int value)
{
	int* ptr{ start };
	for (; ptr < end; ++ptr)
	{
		if (*ptr == value)
			return ptr; // Value found!
	}

	// At this point ptr == end, indicating we haven't found the value 
	return ptr;
}

int main()
{
	int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

	// Search for the first element with value 20.
	int* found{ find(std::begin(arr), std::end(arr), 20) };

	// If an element with value 20 was found, print it
	if (found != std::end(arr))
	{
		std::cout << *found << '\n';
	}

	return 0;
}
