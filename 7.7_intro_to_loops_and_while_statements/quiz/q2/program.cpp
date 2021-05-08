/*
 * Write a program that prints out the letters 'a' through 'z' along with
 * their ASCII codes
*/
#include <iostream>

int main()
{
	char c{ 'a' };

	while ( c <= 'z' )
	{
		std::cout << "Char: " << c << ", ASCII Code: " << static_cast<int>(c) << '\n';
		c += 1;
	}

	return 0;
}
