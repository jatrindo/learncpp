/*
 * The best algorithm for determining whether a value exists in a sorted array
 * is called binary search.
 *
 * Binary search works as follows:
 * 	- Look at the center element of the array (if the array has an even
 * 	number of elements, round down).
 * 	- If the center element is greater than the target element, discard the
 * 	top half of the array (or recurse on the bottom half).
 * 	- If the center element is less than the target element, discard the
 * 	bottom half of the array (or recurse on the top half).
 * 	- If the center element equals the target element, return the index of
 * 	the center element.
 * 	- If you discard the entire array without finding the target element,
 * 	return a sentinel that represents "not found" (in this case, we'll use
 * 	-1 since it's an invalid array index).
 *
 * 3a) Given the following code, write an iterative version of the binarySearch
 * function.
 *
 * 3b) Write a recursive version of the binarySearch function
*/
#include <iostream>
#include <iterator>

/*
 * array is the array to search over.
 * target is the value we're trying to determine exists or not.
 * min is the index of the lower bounds of the array we're searching.
 * max is the index of the upper bounds of the array we're searching.
 * binarySearch() should return the index of the target element if the target is
 * found, -1 otherwise
*/

// Recursive solution for 3b
int binarySearch(const int *array, int target, int min, int max)
{
	// Termination condition: invalid min, max
	if (min > max)
		return -1;

	int center{ min + ((max - min) / 2) }; // this way of calculating midpoint avoids overflow

	// Termination condition: found the target
	if (array[center] == target)
		return center;

	// Determine which half of the array to search next
	if (array[center] > target)
		return binarySearch(array, target, min, center - 1); // Search bottom half
	else
		return binarySearch(array, target, center + 1, max); // Seach top half
}

/*
// Iterative solution for 3a
int binarySearch(const int *array, int target, int min, int max)
{
	while(min <= max)
	{
		int center{ min + ((max - min) / 2) }; // this way of calculating midpoint avoids overflow

		// If we've found the target end early
		if (array[center] == target)
			return center;

		// We haven't found the target, determine which half we should
		// search in next
		if (array[center] > target)
		{
			// The target is in the bottom half
			// max is inclusive, so as to not consider parts of the
			// array we've already considered, we take the index
			// just below center
			max = center - 1;
		}
		else
		{
			// The target is in the top half
			// min is inclusive, so as to not consider parts of the
			// array we've already considered, we take the index
			// just above center
			min = center + 1;
		}
	}

	// If we're here, we haven't found the element
	return -1;
}
*/

int main()
{
	constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if they produce the
	// expected results
	constexpr int numTestValues{ 9 };
	// Here are the test values
	constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	// And here are the expected results for each value
	int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	// Loop through all of the test values
	for (int count{ 0 }; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };

		// If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed. There's something wrong with your code!\n";
	}

	return 0;
}
