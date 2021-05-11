/*
 * Take the program below and modify it so that the ball falls for as many
 * seconds as needed until it reaches the ground
*/
#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen = myConstants::gravity * seconds * seconds / 2;
	double heightNow = initialHeight - distanceFallen;

	// Check whether we've gone under the ground
	// If so, set the height to ground-level
	if (heightNow < 0.0)
		return 0.0;
	else
		return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
	std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

int main()
{
	using namespace std;
	cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	cin >> initialHeight;

	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);

	return 0;
}
