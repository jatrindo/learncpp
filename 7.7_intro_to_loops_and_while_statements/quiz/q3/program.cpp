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

	int outer{ num_lines };
	while (outer > 0)
	{
		int inner{ outer };
		while (inner > 0)
		{
			std::cout << inner-- << ' ';
		}

		std::cout << '\n';
		outer--;
	}

	return 0;
}
