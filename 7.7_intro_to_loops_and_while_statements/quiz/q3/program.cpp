/*
 * Invert the nested loops example so it prints the following:
 *
 * 5 4 3 2 1
 * 4 3 2 1
 * 3 2 1
 * 2 1
 * 1
*/
#include <iostream>

int main()
{
	constexpr int num_lines{ 5 };

	int i{ num_lines };
	while (i > 0)
	{
		int j{ i };
		while (j > 0)
		{
			std::cout << j << ' ';
			j -= 1;
		}
		std::cout << '\n';

		i -= 1;
	}

	return 0;
}
