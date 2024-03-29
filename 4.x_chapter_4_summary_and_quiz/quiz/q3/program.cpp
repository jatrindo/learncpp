#include <iostream>

double askDouble()
{
	std::cout << "Enter a double value: ";
	double d{};
	std::cin >> d;

	return d;
}

char askOperatorSymbol()
{	
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char op_symbol{};
	std::cin >> op_symbol;

	return op_symbol; 
}

void printOperationStatement(double left, double right, char op_symbol, double result)
{
	std::cout << left << " " << op_symbol << " " << right << " is " << result << '\n';
}

void printOperationResult(double left, double right, char op_symbol)
{
	if (op_symbol == '+')
	{
		printOperationStatement(left, right, op_symbol, left + right);
	}
	else if (op_symbol == '-')
	{
		printOperationStatement(left, right, op_symbol, left - right);
	}
	else if (op_symbol == '*')
	{
		printOperationStatement(left, right, op_symbol, left * right);
	}
	else if (op_symbol == '/')
	{
		printOperationStatement(left, right, op_symbol, left / right);
	}
	else
	{
		// Unrecognized symbol -- print nothing
	}

}

int main()
{
	double left{ askDouble() };
	double right{ askDouble() };
	char op_symbol{ askOperatorSymbol() };

	printOperationResult(left, right, op_symbol);
	
	return 0;
}
