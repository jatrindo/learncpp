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

	// Found a string replacement function here:
	// https://en.cppreference.com/w/cpp/string/basic_string/replace
	str.replace(8, 3, "blue");
	
	std::cout << str << '\n'; // I saw a blue car yesterday

	return 0;
}
