/*
 * A program that lets the user know how many years they've lived for each
 * letter in their name (whitespace included)
*/
#include <iostream>
#include <string>

void reportYearPerLetter(double name_length, double age)
{
	double year_per_letter { age / name_length };
	std::cout << "You've lived " << year_per_letter
		  << " years for each letter in your name\n";
}

int main()
{
	std::cout << "Enter your full name: ";
	std::string full_name {};
	std::getline(std::cin, full_name);

	std::cout << "Enter your age: ";
	double age {};
	std::cin >> std::ws;
	std::cin >> age;

	reportYearPerLetter(full_name.length(), age);

	return 0;
}
