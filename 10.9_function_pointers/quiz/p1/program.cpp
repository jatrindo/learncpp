/*
 * In this quiz, we're going to write a verstion of our basic calculator
 * using function pointers.
 *
 * 1a) Create a short program asking the user for two integer inputs and a
 * mathematical operation ('+', '-', '*', '/'). Ensure the user enters a valid
 * operation.
 *
 * 1b) Write functions named add(), subtract(), multiply(), and divide().
 * These should take two integer parameters and return an integer.
 *
 * 1c) Create a type alias named ArithmeticFunciton for a pointer to a
 * function that takes two integer parameters and returns and integer. Use
 * std::function.
 *
 * 1d) Write a function named getArithmeticFunction() that takes an operator
 * character and returns the appropriate function as a function pointer.
 *
 * 1e) Modify your main() function to call getArithmeticFunction(). Call the
 * return value from that function with you inputs and print the result.
*/
#include <iostream>
#include <functional>

//using ArithmeticFunction = int (*)(int, int);  // non-std::function way
using ArithmeticFunction = std::function<int(int, int)>;

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
		case '+': return &add;
		case '-': return &subtract;
		case '*': return &multiply;
		case '/': return &divide;
		default:
			  return &add;	// add by default
	}
}

int askInt()
{
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;
	return i;
}

bool isMathOp(char c)
{
	return (c == '+' || c == '-' || c ==  '*' || c == '/');
}

char askMathOp()
{
	char c{};
	do
	{
		std::cout << "Enter a math operation ('+', '-', '*', '/'): ";
		std::cin >> c;
	}
	while (!isMathOp(c));

	return c;
}

int main()
{
	int a{ askInt() };
	char op{ askMathOp() };
	int b{ askInt() };

	ArithmeticFunction opfunc{ getArithmeticFunction(op) };

	std::cout << "Result is: " << opfunc(a, b) << '\n';
	// std::cout << "Result is: " << (* opfunc)(a, b) << '\n'; // non-std::function way

	return 0;
}
