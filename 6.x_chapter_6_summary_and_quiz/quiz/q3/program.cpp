/*
 * Complere the following program by writing the passOrFail() function,
 * which should return true for the first 3 calls, and false thereafter.
*/
#include <iostream>

constexpr int pass_count_threshold{ 3 };

bool passOrFail()
{
	static int pass_count{ 0 };

	if (pass_count < pass_count_threshold)
	{
		pass_count += 1;
		return true;
	}
	else
	{
		return false;
	}
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
