/*
 * Write a recursive function that takes an integer as input and returns the
 * sum of each individual digit in the integer (e.g 357 = 3 + 5 + 7 = 15).
 *
 * Print the answer for input 93427 (which is 25). Assume the input values are
 * positive.
*/
#include <iostream>

int sum_of_digits(int n)
{
	if (n <= 0)
		return 0;
	return sum_of_digits(n / 10) + (n % 10);
}

int main()
{
	const int n{ 93427 };
	std::cout << "Sum of the digits of " << n << " is "
		  << sum_of_digits(n) << '\n';

	return 0;
}
