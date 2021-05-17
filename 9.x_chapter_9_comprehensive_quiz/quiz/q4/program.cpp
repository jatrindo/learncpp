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

void printCStyleString(char str[])
{
	for (char* ptr{ str }; *ptr != '\0'; ++ptr)
		std::cout << *ptr;
}

int main()
{
	char str[]{ "Hello world!" };

	printCStyleString(str);
	std::cout << '\n';

	return 0;
}
