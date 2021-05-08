/*
 * Complere the following program by writing the passOrFail() function,
 * which should return true for the first 3 calls, and false thereafter.
*/
#include <iostream>

bool passOrFail()
{
	static int passes_left{ 3 };
	return (--passes_left >= 0);
}

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	
	return 0;
}
