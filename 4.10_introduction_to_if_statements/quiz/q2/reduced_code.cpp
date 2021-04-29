/*
 * Reduced (shorter/less verbose) version of reference code.
*/
#include <iostream>

bool isAllowedToTakeFunRide()
{
	std::cout << "How tall are you? (cm)\n";

	double height{};
	std::cin >> height;

	return (height > 140.0); // squooshed!
}

int main()
{
	if (isAllowedToTakeFunRide())
		std::cout << "Have fun!\n";
	else
		std::cout << "Sorry, you're too short.\n";

	return 0;
}
