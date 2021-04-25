#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter a number: ";
	int n {};
	std::cin >> n;
	return n;
}

void writeAnswer(int ans)
{
	std::cout << "The answer is " << ans << '\n';
	return;
}

