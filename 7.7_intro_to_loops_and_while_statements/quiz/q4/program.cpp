/*
 * Now make the numbers print like this:
 *   
 *         1
 *       2 1
 *     3 2 1
 *   4 3 2 1
 * 5 4 3 2 1
*/
#include <iostream>

int main()
{
	// We print 5 column's worth of numbers always (even if there aren't
	// always five numbers to fill them)
	constexpr int num_columns{ 5 };

	// The current row we're on
	int row{ 1 };
	while ( row <= num_columns )
	{
		// We always print 5 column's worth of numbers, decreasing
		int number{ num_columns };
		while ( number >= 1)
		{
			// We only print numbers equal to or less than the
			// row we're currently on
			if (number <= row)
				std::cout << number << ' ';
			else
				std::cout << ' ' << ' '; // But we still print 5 column's worth of numbers!

			number--;
		}

		// Move onto next row
		std::cout << '\n';
		row++;
	}

	return 0;
}
