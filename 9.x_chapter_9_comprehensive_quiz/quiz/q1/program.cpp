/*
 * Pretend you're writing a game where the player can hold 3 types of items:
 * health potions, torches, and arrows.
 *
 * Create an enum to identify the different types of items, and a std::array
 * to store the number of each item the player is carrying (The enumerators
 * are used as indexes of the array).
 * The player should start with 2 health potions, 5 torches, and 10 arrows.
 *
 * Write a function called countTotalItems() that returns how many items the
 * player has in total.
 *
 * Have your main() function print the output of countTotalItems() as well as
 * the number of torches.
*/
#include <iostream>
#include <array>
#include <numeric> // for std::reduce/std::accumulate

// We're using enums as array indexes, so we decalre the enums inside a
// namespace rather than declare an enum class.
//
// Otherwise we'd have to deal with a lot of static_casts everywhere since
// enums within an enum class aren't implicitly converted into integers by
// the compiler.
//
// Reference: learncpp.com, chapter 9.2
namespace ItemTypes
{
	// not necessary to have a name for the below enum since I don't use it
	enum ItemTypes
	{
		health_potion,
		torches,
		arrows,

		max_items
	};
}

using inventory_type = std::array<int, ItemTypes::max_items>;

int countTotalItems(const inventory_type& inventory)
{
	// std::reduce not available, fall back to std::accumulate
	return std::accumulate(inventory.begin(), inventory.end(), 0);
}

int main()
{
	inventory_type inventory{};

	// Items instantiated this way so that order of enums doesn't matter
	inventory[ItemTypes::health_potion] = 2;
	inventory[ItemTypes::torches] = 5;
	inventory[ItemTypes::arrows] = 10;

	std::cout << "Number of total items: "
		  << countTotalItems(inventory) << '\n';

	std::cout << "Number of torches: "
		  << inventory[ItemTypes::torches] << '\n';

	return 0;
}
