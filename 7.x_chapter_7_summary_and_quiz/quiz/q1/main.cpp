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

void printHeightForTime(double height, int time)
{
	std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";
}

void calculateAndPrintHeightUntilGround(double initialHeight)
{
	int time{ 0 };
	double currentHeight{ initialHeight };

	do
	{
		currentHeight = calculateHeight(currentHeight, time);
		printHeightForTime(currentHeight, time);
		time++;
	} while (currentHeight > 0.0);

}

int main()
{
	using namespace std;
	cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	cin >> initialHeight;

	calculateAndPrintHeightUntilGround(initialHeight);

	return 0;
}
