#include <iostream>

int readNumber();
void writeAnswer(int ans);

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

int main()
{
	int a{ readNumber() };
	int b{ readNumber() };
	writeAnswer(a + b);
	return 0;
}
