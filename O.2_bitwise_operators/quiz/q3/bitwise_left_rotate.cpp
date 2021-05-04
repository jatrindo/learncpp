#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
	// Your code here -- don't use bitset.test() and bitset.set()
	
	// Move the leftmost bit to the 0th position and bit-OR it with the
	// left-shifted bits
	return (bits >> 3) | (bits << 1);
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
