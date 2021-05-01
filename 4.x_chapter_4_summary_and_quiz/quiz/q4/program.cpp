#include "constants.h"
#include <iostream>

double askInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initial_height{};
	std::cin >> initial_height;
	return initial_height;
}

double calculateHeightAfterXSeconds(double initial_height, double seconds)
{
	double distance_fallen{ (gravity_constant * (seconds * seconds)) / 2 };

	double final_height{ initial_height - distance_fallen };
	if (final_height > 0.0)
	{
		return final_height;
	}
	else
	{
		return 0.0;
	}
}

void printHeightAfterXSeconds(double initial_height, double seconds)
{
	double height{ calculateHeightAfterXSeconds(initial_height, seconds) };

	if (height > 0.0)
	{
		std::cout << "At " << seconds
			  << " seconds, the ball is at height: "
			  << height  << " meters\n";
	}
	else
	{
		std::cout << "At " << seconds
			  << " seconds, the ball is on the ground\n";
	}
}

int main()
{
	double initial_height{ askInitialHeight() };

	printHeightAfterXSeconds(initial_height, 0.0);
	printHeightAfterXSeconds(initial_height, 1.0);
	printHeightAfterXSeconds(initial_height, 2.0);
	printHeightAfterXSeconds(initial_height, 3.0);
	printHeightAfterXSeconds(initial_height, 4.0);
	printHeightAfterXSeconds(initial_height, 5.0);

	return 0;
}
