/*
 * In the following code, modify str so that its value is "I saw a blue car
 * yesterday" without repeating the string (i.e don't do this:
 * str = "I saw a blue car ysterday"; )
 *
 * You only need to call one function to replace "red" with "blue"
*/
#include <iostream>
#include <string>

int main()
{
	std::string str{ "I saw a red car yesterday." };

	// ...
	
	std::cout << str << '\n'; // I saw a blue car yesterday

	return 0;
}
