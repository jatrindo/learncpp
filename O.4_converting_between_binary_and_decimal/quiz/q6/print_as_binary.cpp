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

// Prints either a '1' or '0' and returns either a decremented i, depending on
// whether the given power of 2 'fits' within (i.e. is less than) i
//
// Prints '1' if the given power of 2 'fits' within i
// Prints '0' if the given power of 2 is larger than i (i.e. does not fit)
//
// If the given power of 2 fits within i, we return i decremented by the
// given power of two.
// Otherwise, we return i, unaltered
int print_and_decrement_if_fits(int i, int pwr_of_2)
{
	if (i >= pwr_of_2)
	{
		// Power of 2 does fit within i
		std::cout << '1';
		return i - pwr_of_2;
	}

	// Power of 2 does not fit within i
	std::cout << '0';
	return i;
}

// Assumes i is within the range of [0,255]
void print_as_binary(int i)
{
	i = print_and_decrement_if_fits(i, 128);
	i = print_and_decrement_if_fits(i, 64);
	i = print_and_decrement_if_fits(i, 32);
	i = print_and_decrement_if_fits(i, 16);
	std::cout << ' ';
	i = print_and_decrement_if_fits(i, 8);
	i = print_and_decrement_if_fits(i, 4);
	i = print_and_decrement_if_fits(i, 2);
	i = print_and_decrement_if_fits(i, 1);
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
