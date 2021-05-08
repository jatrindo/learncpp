/*
 * Write a function called calculate() that takes two integers and a char
 * representing one of the following mathematical operations: +, -, *, /, or
 * % (modulus).
 *
 * Use a switch statement to perform the appropriate mathematical operation
 * on the integers, and return the result.
 *
 * If an invalid operator is passed into the function, the function should
 * print an error.
 *
 * For the division operator, do an integer division.
*/
#include <iostream>

int calculate(int x, int y, char op)
{
	switch (op)
	{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		case '%':
			return x % y;
		default:
			std::cerr << "Invalid operator '" << op << "' passed.\n";
			return 0;
	}
}

int askInteger()
{
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;
	return i;
}

char askOperator()
{
	std::cout << "Enter an operator (one of +, -, *, /, %): ";
	char op;
	std::cin >> op;
	return op;
}

int main()
{
	int x{ askInteger() };
	int y{ askInteger() };
	int op{ askOperator() };

	std::cout << "Result was: " << calculate(x, y, op) << '\n';

	return 0;
}

