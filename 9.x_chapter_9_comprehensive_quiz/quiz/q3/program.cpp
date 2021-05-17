/*
 * Write your own function to swap the value of two integer variables.
 *
 * Write a main() function to test it.
*/
#include <iostream>

void swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}

int main()
{
	std::cout << "Testing swap....\n";

	int a{ 5 };
	int b{ 7 };

	std::cout << "Before:\n";
	std::cout << "a = " << a << ", b = " << b << '\n';

	swap(a, b);

	std::cout << "After:\n";
	std::cout << "a = " << a << ", b = " << b << '\n';

	return 0;
}
