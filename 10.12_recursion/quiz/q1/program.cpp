/*
 * A factorial of an integer N (written N!) is defined as the product
 * (multiplation) of all the numbers between 1 and N (0! =1).
 *
 * Write a recursive function called factorial that returns the factorial of
 * the input. Test it with the first 7 factorials
*/
#include <iostream>

int factorial(int n)
{
	if (n == 0)
		return 1;

	return factorial(n - 1) * n;
}

int main()
{
	for (int i{ 0 }; i < 7; ++i)
		std::cout << "factorial(" << i << ") is " << factorial(i) << '\n';

	return 0;
}
