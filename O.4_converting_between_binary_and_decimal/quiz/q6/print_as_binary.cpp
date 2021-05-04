/*
 * Write a program that asks the user to input a number between 0 and 255.
 * Print this number as an 8-bit binary number (of the form #### ####).
 * Don't use any bitwise operators. Don't use std::bitset
*/
#include <iostream>

int ask_number()
{
	std::cout << "Input a number between 0 and 255: ";
	int n{};
	std::cin >> n;
	return n;
}

// Prints '1' or '0' on whether i fits the given power of 2
// ('1' if it does, '0' if it doesn't)
//
// If i fits, it returns i decremented by the power of 2, otw 
// returning just i. unaltered
int print_and_return_decremented_if_fit(int i, int pwr_of_2) 
{
	if (i < pwr_of_2)
	{
		std::cout << '0';
		return i;
	}

	std::cout << '1';
	return i - pwr_of_2;
}

// Assumes i is within the range of [0,255]
void print_as_binary(int i)
{
	i = print_and_return_decremented_if_fit(i, 128);
	i = print_and_return_decremented_if_fit(i, 64);
	i = print_and_return_decremented_if_fit(i, 32);
	i = print_and_return_decremented_if_fit(i, 16);
	std::cout << ' ';
	i = print_and_return_decremented_if_fit(i, 8);
	i = print_and_return_decremented_if_fit(i, 4);
	i = print_and_return_decremented_if_fit(i, 2);
	i = print_and_return_decremented_if_fit(i, 1);
	std::cout << '\n';
}


int main()
{
	int n{ ask_number() };

	if (!(n >= 0 && n <= 255))
	{
		std::cout << "Number needs to be between 0 and 255, inclusive\n";
		return 1;
	}

	print_as_binary(n);

	return 0;
}
