#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ 0 };
	std::cin >> num;
	
	std::cout << "Double that number is: " << num * 2 << std::endl;
	std::cout << "Triple that number is: " << num * 3 << std::endl;

	return 0;
}
