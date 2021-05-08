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
	constexpr int num_columns{ 5 };

	int outer{ 1 };
	while ( outer <= num_columns )
	{
		int inner{ num_columns };
		while ( inner > 0)
		{
			if (inner > outer)
			{
				std::cout << ' ' << ' ';
			}
			else
			{
				std::cout << inner << ' ';
			}

			inner--;
		}

		std::cout << '\n';
		outer++;
	}

	return 0;
}
