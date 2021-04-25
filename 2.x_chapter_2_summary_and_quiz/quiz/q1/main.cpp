#include <iostream>

int readNumber();
void writeAnswer(int ans);

int readNumber()
{
	int n{};
	std::cin >> n;

	return n;
}

void writeAnswer(int ans)
{
	std::cout << ans << '\n';
	return;
}

int main()
{
	int a{ readNumber() };
	int b{ readNumber() };

	int answer = a + b;

	writeAnswer(answer);

	return 0;
}
