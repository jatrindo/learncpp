/*
 * Use the (integrated) debugger to step through this program and watch the
 * value of x.
 * Based on the information you learn, fix the following program.
*/

#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is:" << x;
}

int main()
{
	int x {};
	x = readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}
