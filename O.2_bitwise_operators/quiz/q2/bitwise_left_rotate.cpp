#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
	// Your code here -- okay to use bitset.test() and set()
	const bool leftmost_bit { bits.test(3) };

	bits = bits << 1;

	// If the leftmost bit was set before, it'll be the rightmost bit now
	if (leftmost_bit)
		bits.set(0);

	return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
