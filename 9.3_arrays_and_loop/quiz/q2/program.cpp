/*
 * Given the array in question 1:
 *
 * Ask the user for a number between 1 and 9. If the user does not enter a
 * number between 1 and 9, repeatedly ask for an integer value until they do.
 *
 * Once they have entered a number between 1 and 9, print the array. Then
 * search the array for the value that the user entered and print the index
 * of that element.
 *
 * You can test std::cin for invalid input by using the following code:
 *
 *	// if the user entered something invalid
 *	if (std::cin.fail())
 *	{
 *		std::cin.clear();
 *		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
 *	}
*/
#include <iostream>

int askNumberInRange(const int min, const int max)
{
	while (true)
	{
		std::cout << "Enter a number between " << min
			<< " and " << max << ", inclusive: ";
		int response{};
		std::cin >> response;

		// If the user pressed ^D, we're assuming they want to exit
		// the program
		if (std::cin.eof())
		{
			std::exit(0);
		}

		if (response >= min && response <= max)
			return response;

		std::cout << "Invalid response.\n";

		// If the extraction failed, clear out the input buffer
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void printArray(const int array[], const int array_size)
{
	for (int i{ 0 }; i < array_size; i++)
		std::cout << array[i] << ' ';
	std::cout << '\n';
}

// Returns index of element, if found. Otherwise returns -1
int getIndexOfElement(const int element, const int array[], const int array_size)
{
	for (int i{ 0 }; i < array_size; i++)
	{
		if (array[i] == element)
			return i;
	}

	// Return -1 if element was not found
	return -1;
}


int main()
{
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	constexpr int array_size{ sizeof(array) / sizeof(array[0]) };

	int num{ askNumberInRange(1, 9) };

	// Print the array
	printArray(array, array_size);

	// Print the index the user's number is at in the array
	std::cout << "The element '" << num << "' is located at index "
		  << getIndexOfElement(num, array, array_size) << '\n';

	return 0;
}
