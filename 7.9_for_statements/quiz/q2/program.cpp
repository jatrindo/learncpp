/*
 * Write a function named sumTo() that takes an integer parameter named
 * 'value', and returns the sum of all numbers from 1 to value
 *
 * For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5
*/
#include <iostream>

int sumTo(int value)
{
	int sum{ 0 };
	for (int i{ 1 }; i <= value; i++)
		sum += i;
	return sum;
}

int askInteger()
{
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;
	return i;
}

int main()
{
	int value{ askInteger() };
	std::cout << sumTo(value) << '\n';

	return 0;
}
