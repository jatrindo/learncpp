/*
 * In designing a game, we decide we want to have monsters, because everyone
 * likes fighting monsters.
 *
 * Declare a struct that represents your monster. The monster should have a
 * type that can be one of the following: an ogre, a dragon, an orc, a giant
 * spider, or a slime. Use an enum class for this.
 *
 * Each individual monster should also have a name (use a std::string), as
 * well as an amount of health that represents how much damage they can take
 * before they die.
 *
 * Write a function named printMonster() that prints out all of the struct's
 * members. Instantiate an ogre and a slime, initialize them using an
 * initializer list, and pass them to printMonster().
 *
 * Your program should produce the following output:
 *
 * This Ogre is named Torg and has 145 health.
 * This Slime is named Blurp and has 23 health.
*/
#include <iostream>
#include <string>

enum class MonsterType
{
	Ogre,
	Dragon,
	Orc,
	GiantSpider,
	Slime,
};

struct Monster
{
	std::string name{};
	MonsterType type{};
	int health{};
};

std::string getMonsterTypeAsString(MonsterType t)
{
	std::string name{};

	switch (t)
	{
		case MonsterType::Ogre:
			name = "Ogre";
			break;
		case MonsterType::Dragon:
			name = "Dragon";
			break;
		case MonsterType::Orc:
			name = "Orc";
			break;
		case MonsterType::GiantSpider:
			name = "GiantSpider";
			break;
		case MonsterType::Slime:
			name = "Slime";
			break;
		default:
			name = "???";
	}

	return name;
}

void printMonster(Monster m)
{
	std::cout << "This " << getMonsterTypeAsString(m.type)
		  << " is named " << m.name
		  << " and has " << m.health << " health.\n";
}

int main()
{
	Monster ogre{"Torg", MonsterType::Ogre, 145};
	Monster slime{"Blurp", MonsterType::Slime, 23};

	printMonster(ogre);
	printMonster(slime);

	return 0;
}
