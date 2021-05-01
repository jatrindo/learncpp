/*
 * Write a program that asks the user to input an integer, and tells the
 * user whether the number is even or odd.
 *
 * Write a function called isEven() that returns true if an integer passed to
 * it is even, and false otherwise. Use the modulus operator to test whether
 * the integer parameter is even.
*/
#include <iostream>

bool isEven(int x)
{
	return (x % 2) == 0;
}

int main()
{
	std::cout << "Enter an integer: ";

	int i{};
	std::cin >> i;

	if (isEven(i))
	{
		std::cout << i << " is even\n";
	}
	else
	{
		std::cout << i << " is odd\n";
	}

	return 0;
}
