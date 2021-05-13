/*
 * Set up an enum with the names of the following animals: chicken, dog, cat,
 * elephant, duck, and snake.
 *
 * Put the enum in a namespace.
 *
 * Define an array with an element for each of the animals, and use an
 * initializer list to initialize each element to hold the number of legs
 * that an animal has.
 *
 * Write a main function that prints the number of legs an elephant has, using
 * the enumerator.
*/
#include <iostream>

namespace Animals
{
	enum Animals
	{
		chicken,
		dog,
		cat, 
		elephant,
		duck,
		snake,

		max_animals
	};
}

int main()
{
	int num_legs[Animals::max_animals] {
		2, 4, 4, 4, 2, 0,
	};

	std::cout << "An elephant has " << num_legs[Animals::elephant]
		  << " legs\n";

	return 0;
}
