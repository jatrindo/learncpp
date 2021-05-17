/*
 * Write a function to print a C-style string character by character.
 *
 * Use a pointer to step through each character of the string and print that
 * character. Stop when you hit the null terminator.
 *
 * Write a main function that tests the function with the string literal
 * "Hello world!".
*/
#include <iostream>

void printCStyleString(const char str[])
{
	for (; *str != '\0'; ++str)
		std::cout << *str;
}

int main()
{
	char str[]{ "Hello world!" };

	printCStyleString(str);
	std::cout << '\n';

	return 0;
}
