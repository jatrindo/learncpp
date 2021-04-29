/*
 * Wire a program that asks the user to enter a single digit integer. If the
 * user enters a single digit that is prime (2, 3, 5, or 7), print
 * "The digit is prime". Otherwise, print "The digit is not prime".
*/
#include <iostream>

bool isPrime(int x)
{
	if (x == 2)
		return true;
	else if (x == 3)
		return true;
	else if (x == 5)
		return true;
	else if (x == 7)
		return true;
	else
		return false;
}

int main()
{
	std::cout << "Enter a single digit number: ";

	int x{};
	std::cin >> x;

	if (isPrime(x))
		std::cout << "The digit is prime\n";
	else
		std::cout << "The digit is not prime\n";

	return 0;
}
