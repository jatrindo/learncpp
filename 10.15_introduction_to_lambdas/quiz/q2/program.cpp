/*
 * Use std::sort and a lambda in the following code to sort the seasons by
 * ascending average temperature
 *
 * This program should print:
 *
 * 	Winter
 * 	Spring
 * 	Fall
 * 	Summer
 *
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
	std::string_view name{};
	double averageTemperature{};
};

int main()
{
	std::array<Season, 4> seasons{
		{ { "Spring", 285.0 },
		  { "Summer", 296.0 },
		  { "Fall", 288.0 },
		  { "Winter", 263.0 } }
	};
	
	/*
	 * Use std::sort here
	*/
	std::sort(seasons.begin(), seasons.end(),
			[](const auto& s1, const auto& s2)
			{
				// Note: std::sort's comparison function
				// expects 'true' returned if the first arg
				// is 'less than' (i.e. 'ordered before') the
				// second arg
				return s1.averageTemperature < s2.averageTemperature;
			}
	);

	for (const auto& season : seasons)
	{
		std::cout << season.name << '\n';
	}

	return 0;
}
