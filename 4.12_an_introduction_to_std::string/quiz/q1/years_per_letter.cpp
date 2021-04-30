/*
 * A program that lets the user know how many years they've lived for each
 * letter in their name (whitespace included)
*/
#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter your full name: ";
	std::string full_name{};
	std::getline(std::cin >> std::ws, full_name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	int num_letters{ static_cast<int>(full_name.length()) };
	double years_per_letter { static_cast<double>(age) / num_letters };
	std::cout << "You've lived " << years_per_letter
		  << " years for each letter in your name\n";

	return 0;
}
