/*
 * Add two optimizations to the bubble sort algorithm you wrote in the previous
 * quiz question:
 *
 * 	- Notice how with each iteration of bubble sort, the biggest number
 * 	remaining gets bubbled to the end of the array. After the first
 * 	iteration, the last array element is sorted. After the second
 * 	iteration, the second to last array element is sorted too. And so on...
 * 	With each iteration, we don't need to recheck elements that we know are
 * 	already sorted. Change your loop to not re-check elements that are
 * 	already sorted.
 *
 * 	- If we go through an entire iteration without doing a swap, then we
 * 	know the array must already be sorted. Implement a check to determine
 * 	whether any swaps were made this iteration, and if not, terminate the
 * 	loop early. If the loop was terminated early, print on which iteration
 * 	the sort ended early.
 *
 * Your output should match this:
 * 
 * Early termination on iteration 6
 * 1 2 3 4 5 6 7 8 9
*/
#include <iostream>
#include <utility>

void printArray(int array[], std::size_t array_size)
{
	for (std::size_t i{ 0 }; i < array_size; i++)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';
}

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
	for (std::size_t last_unsorted_index{ array_size - 1 }, iteration{ 1 };
			 last_unsorted_index > 0;
			 last_unsorted_index--, iteration++)
	{
		// Tracks if we've done a swap or not
		bool no_swaps{ true };

		// Bubble from the beginning to the last index of the unsorted
		// portion of the array
		//
		// Note: There was a nasty off-by-1 error in the loop back when
		// I set the condition to be (i <= last_unsorted_index)
		//
		// The error would manifest itself when there was no function
		// call being made to printArray(), when printArray()'s code
		// was instead placed directly at the bottom of main().
		//
		// The error (showing as an unsorted array with only the values
		// between [0,8] (and not [1,9]) being printed to console)
		// would also manifest when both a call to printArray() and
		// printArray()'s code were placed at the bottom of main.
		//
		// Only when a lone printArray() call was made did the program
		// operate correctly.
		//
		// Nasty stuff!
		for (std::size_t i{ 0 }; i < last_unsorted_index; i++)
		{
			// Nudge the larger value up if it isn't in the higher
			// index already
			if (array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
				no_swaps = false;
			}
		}

		// We can terminate early if there were no swaps
		if (no_swaps)
		{
			std::cout << "Early termination on iteration " << iteration << '\n';
			break;
		}
	}

	// Print out the now sorted array
	printArray(array, array_size);

	return 0;
}
