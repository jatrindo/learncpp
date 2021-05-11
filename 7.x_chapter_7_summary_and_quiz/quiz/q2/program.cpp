/*
 * A prime number is a natural number greater than 1 that is evenly divisible
 * (with no remainder) only by 1 and itself. Complete the following program
 * by writing the isPrime() function using a for loop
*/
#include <iostream>
#include <cassert>

bool isPrime(int x)
{
	if (x <= 1)
		return false; // by the above definition

	// Test to see that all the numbers between [2..x) do _not_ divide
	// evenly
	for (int i{ 2 }; i < x; i++)
	{
		if ((x % i) == 0)
			return false;
	}

	return true;
}

int main()
{
	assert(!isPrime(0));
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!\n";

	return 0;
}
