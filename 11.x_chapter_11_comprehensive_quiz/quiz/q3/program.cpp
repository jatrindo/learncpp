/*
 * Let's make a random monster generator. This one should be fun.
 *
 * a) First, let's create an enumeration of monster types named MonsterType.
 * Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton,
 * Troll, Vampire, and Zombie. Add an additional max_monster_types enum so we
 * can count how many enumerators there are.
 *
 *
 * b) Now, let's create our Monster class. Our Monster will have 4 attributes
 * (member variables): a type (MonsterType), a name (std::string), a roar
 * (std::string), and the number of hit points (int). Create a Monster class
 * that has these 4 member variables.
 *
 *
 * c) enum MonsterType is specific to Monster, so move the enum inside the class
 * as a public declaration. When the enum is inside the class, the "Monster" in
 * "MonsterType" is redundant, so it can be removed.
 *
 *
 * d) Create a constructor that allows you to initialize all of the member
 * variables.
 *
 * The following program should compile:
 *
 * 	int main()
 * 	{
 * 		Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
 * 		
 * 		return 0;
 * 	}
 *
 *
 * e) Now we want to be able to print our monster so we can validate it's
 * correct. To do that, we're going to need to write a function that converts a
 * Monster::Type into a string. Write that function (called getTypeString()), as
 * well as a print() member function.
 *
 * The following program should compile:
 *
 * 	int main()
 * 	{
 * 		Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
 * 		skeleton.print();
 *
 * 		return 0;
 * 	}
 *
 *
 * f) Now we can create a random monster generator. Let's consider how our
 * MonsterGenerator class will work. Ideally, we'll ask it to give us a Monster,
 * and it will create a random one for us. We don't need more than one
 * MonsterGenerator. This is a good candidate for a static class (one in which
 * all functions are static).
 *
 * Create a static MonsterGenerator class.
 *
 * Create a static function named generateMonster(). This should return a
 * Monster. For now, make it return an anonymous Monster(Monster::type::skeleton, "Bones", "*rattle*", 4);
 *
 * The following program should compile:
 *
 * 	int main()
 * 	{
 * 		Monster m{ MonsterGenerator::generateMonster() };
 * 		m.print();
 *
 * 		return 0;
 * 	}
 *
 * and print:
 * 
 * 	Bones the skeleton has 4 hit points and says *rattle*
 *
 *
 * g) Now, MonsterGenerator needs to generate some random attributes. To do
 * that we'll need to make use of this handy function:
 * 
 * int getRandomNumber(int min, int max)
 * {
 * 	static constexpr double fraction{ 1.0 /
 * 		(static_cast<double>(RAND_MAX)) + 1.0 }; // static used for efficiency, so we only calculate this value once
 * 	// evenly distribute the random number across our range
 * 	return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
 * }
 * 
 * However, because MonsterGenerator relies directly on this function, let's put it inside the class, as a static function.
 * 
 *
 * h) Now edit function generateMonster() to generate a random Monster::Type
 * (between 0 and Monster::Type::max_monster_types - 1_ and a random hits
 * (between 1 and 100). This should be fairly straightforward.
 *
 * Once you've done that, define two static fixed arrays of size 6 inside the
 * function (named s_names and s_roars) and initialize them with 6 names and 6
 * sounds of your choice. Pick a random name from these arrays.
 *
 * The following program should compile:
 *
 * #include <ctime> // for time()
 * #include <cstdlib> // for rand() and srand()
 * 
 * int main()
 * {
 * 	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
 * 	std::srand(); // If using Visual Studio, discard first random value
 * 
 * 	Monster m{ MonsterGenerator::generateMonster() };
 * 	m.print();
 * 
 * 	return 0;
 * }
*/
#include <string>
#include <iostream>

class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,

		max_monster_types
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hit_points{};

public:
	Monster(Type type, const std::string& name, const std::string& roar, int hit_points)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hit_points{ hit_points }
	{
	}

	// Since we're returning string known at compile-time, we could return
	// a std::string_view instead of std::string to avoid the additional
	// run-time cost
	std::string_view getTypeString() const
	{
		switch (m_type)
		{
			case Type::dragon:	return "dragon";
			case Type::goblin:	return "goblin";
			case Type::ogre:	return "ogre";
			case Type::orc:		return "orc";
			case Type::skeleton:	return "skeleton";
			case Type::troll:	return "troll";
			case Type::vampire:	return "vampire";
			case Type::zombie:	return "zombie";
			default:		return "???";
		}
	}

	void print() const
	{
		std::cout << m_name << " the " << getTypeString()
			  << " has " << m_hit_points << " hit points and says "
			  << m_roar << '\n';
	}
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		return Monster(Monster::Type::skeleton, "Bones", "*rattle*", 4);
	};

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 /
			(static_cast<double>(RAND_MAX) + 1.0) }; // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	};
};

int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
