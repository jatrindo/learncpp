/*
 * Write a program that asks the user to enter two integers, one named
 * 'smaller', the other named 'larger'
 *
 * If the user enters a smaller value for the second integer, use a block
 * and temporary variable to swap the smaller and larger values (so that
 * smaller value is in 'smaller' and the larger value in 'larger')
 *
 * Then print the values of the 'smaller' and 'larger' variables.
 *
 * Add comments to your code indicating where each variable dies
 */
#include <iostream>

int getInteger()
{
	int i{};
	std::cin >> i;
	return i;
} // 'i' dies here


int main()
{
	std::cout << "Enter an integer: ";
	int smaller{ getInteger() };

	std::cout << "Enter a larger integer: ";
	int larger{ getInteger() };

	if (smaller > larger)
	{
		std::cout << "Swapping the values...\n";
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	} // 'temp' dies here

	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';

	return 0;
} // 'smaller' and 'larger' die here
