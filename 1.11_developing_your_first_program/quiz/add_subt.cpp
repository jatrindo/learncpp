#include <iostream>

int main()
{
	int first{};
	std::cout << "Enter an integer: ";
	std::cin >> first;

	int second{};
	std::cout << "Enter another integer: ";
	std::cin >> second;

	std::cout << first << " + " << second << " is " << first + second
		<< "." << std::endl;
	std::cout << first << " - " << second << " is " << first - second
		<< "." << std::endl;

	return 0;
}
