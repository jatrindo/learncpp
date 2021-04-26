#include <iostream>
#include <plog/Log.h>

int getUserInput()
{
	LOGD << "getUserInput() called";

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Init the logger
	
	LOGD << "main() called";

	int x{ getUserInput() };
	std::cout << "You entered: " << x;

	return 0;
}
