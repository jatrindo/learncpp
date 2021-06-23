/*
 * Challenge time! The following quiz question is more difficult and lengthy.
 *
 * We're going to write a simple game where you fight monsters. The goal of this
 * game is to collect as much gold as you can before you die or get to level 20.
 *
 * Our program is going to consist of 3 classes: A Creature class, a Player
 * class, and a Monster class. Player and Monster both inherit from Creature.
 *
 * a) First create the Creature class.
 *
 * Creatures have 5 attributes: A name (std::string), a symbol (a char), and
 * amount of health (int), the amount of damage they do per attack (int), and
 * the amount of gold they are carrying (int). Implement these as class members.
 *
 * Write a full set of getters (a get function for each member).
 *
 * Aff three other functions: void reduceHealth(int) reduces's the Creature's
 * health by an integer amount. bool isDead() returns true when the Creature's
 * health is 0 or less. void addGold(int) adds gold to the Creature.
 *
 * The following program should run: [ Listing MA ]
 *
 * And produce the result:
 *
 *  The orc has 3 health and is carrying 15 gold.
 *
 *
 * b) Now we're going to create the Player class.
 *
 * The Player class inherits from Creature. Player has one additional member,
 * the player's level, which starts at 1. 
 *
 * The player has a custom name (entered by the user), users symbol '@', has 10
 * health, does 1 damage to start, and has no gold.
 *
 * Write a function called levelUp() that increases the player's level and
 * damage by 1. Also write a getter for the level member. Finally, write a
 * function called hasWon() that returns true if the player has reached level
 * 20.
 *
 * Write a new main() function that asks the user for their name and produces
 * the output as follows:
 *
 *  Enter your name: Alex Welcome, Alex. You have 10 health and are carrying 0
 *  gold.
 *
 *
 * c) Next up is the Monster class.
 *
 * Monster also inherits from Creature. Monsters have no non-inherited member
 * variables.
 *
 * First, write an empty Monster class inheriting from Creature, and then add an
 * enum inside the Monster class named Type that contains enumerators for the 3
 * monsters that we'll have in this game: DRAGON, ORC, and SLIME (you'll also
 * want a max_types enumerator, as that will come in handy in a bit)
 *
 *
 * d) Each monster type will have a different name, symbol, starting health,
 * gold, and damage. Here is a table of stats for each monter Type:
 *
 * |    Type    |   Name    |   Symbol  |   Health  |   Damage  |   Gold    |
 * --------------------------------------------------------------------------
 * |    dragon  |   dragon  |   D       |   20      |   4       |   100     |
 *
 * |    orc     |   orc     |   o       |   4       |   2       |   25      |
 *
 * |    slime   |   slime   |   s       |   1       |   1       |   10      |
 *
 * Next step is to write a Monster constructor, so we can create monster.
 *
 * The Monster constructor should take a Type enum as a parameter, and then
 * create a Monster with the appropriate stats for that kind of monster.
 *
 * There are a number of different ways to implement this (some better, some
 * worse). However in this case, because all of out monster attributes are
 * predefined (not random), we'll use a lookup table. A lookup table is an array
 * that hold all of the predefined attributes. We can then use the lookup table
 * to lookk up the attributes for a given monster as needed.
 *
 * So how do we implement this lookup table? It's not hard. We just need an
 * array that contains an element for each monster Type. Each array element will
 * contain a Creature that contains all of the predefined attribute values for
 * that Type of Monster. We place this array inside of a static member function
 * of Monster so that we can get a default Creature for a given Monster::Type.
 *
 * The definition of the lookup table is as follows:
 *
 *  // As a private member of Monster
 *  static const Creature& getDefaultCreature(Type type)
 *  {
 *      static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
 *          {
 *              { "dragon", 'D', 20, 4, 100 },
 *              { "dragon", 'D', 20, 4, 100 },
 *              { "dragon", 'D', 20, 4, 100 }
 *          }
 *      };
 *
 *      return monsterData.at(static_cast<std::size_t>(type));
 *  }
 *
 * Now we can call this function to lookup any values we need! For example, to
 * get a Dragon's gold, we can call getDefaultCreature(Type::dragon).getGold().
 *
 * Use this function and delegating constructors to implement your Monster
 * constructor.
 *
 * The following program should compile: [ Listing MD ]
 *
 * and print:
 *
 *  A orc (o) was created.
 *
 *
 * e) Finally, add a static function to Monster named getRandomMonster().
 *
 * This function should pick a random number from 0 to max_types-1 and return a
 * monster (by value) with that Type (you'll need to static_cast the int to a
 * Type to pass it to the Monster constructor).
 *
 * Lesson 8.5 -- Random number generation contains code you can use to pick a
 * random number.
 *
 * The following main function should run: [ Listing ME ]
 *
 * The results of this program should be randomized.
 *
 *
 * f) We're finally set to write our game logic!
 *
 * Here are the rules for the game:
 *
 *  - The player encounters one randomly generated monster at a time.
 *  - For each monster, the player has two choices: (R)un or (F)ight.
 *  - If the player decides to Run, they have a 50% chance of escaping.
 *  - If the player escapes, they move to the next encounter with no ill
 *    effects.
 *  - If the player does not escape, the monster gets a free attack, and the
 *    player chooses their next action./
 *  - If the player chooses to fight, the player attacks first. The monster's
 *    health is reduced by the player's damage.
 *  - If the monster dires, the player takes any gold the monster is carrying.
 *    The player also levels up, increasing their level and damage by 1.
 *  - If the monster does not die, the monster attacks the player back. The
 *    player's health is reduced by the monster's damage.
 *  - The game ends when the player has died (loss) or reached level 20 (win)
 *  - If the player dies, the game should tell the player what level they were
 *    and how much gold they had.
 *  - If the player wins, the game should tell the player they won, and how much
 *    gold they had.
 *
 *
 * g) Extra credit:
 *
 * Reader Tom didn't sharpen his sword enough to defeat the mighty dragon. Help
 * him by implementing the following potions in different sizes:
 *
 * |   Type        |   Effect (Small)  |   Effect (Medium) |   Effect (Large)  |
 * -----------------------------------------------------------------------------
 * |   Health      |   +2 Health       |   +2 Health       |   +5 Health       |
 * |   Strength    |   +1 Damage       |   +1 Damage       |   +1 Damage       |
 * |   Poison      |   -1 Health       |   -1 Health       |   -1 Health       |
 *
 * Feel freee to get creative and add more potions or change their effects!
 *
 * The player has a 30% chance of finding a potion after every won fight and has
 * the choice between drinking or not drinking it.
 *
 * If the player doesn't drink the potion, it disappears. The player doesn't
 * know what type of potion was found until the player drinks it, at which point
 * the type and size of the potion is revealed and the effect is applied.
 *
 * Add a potion Potion class that has a type and size member variable, along
 * with a member function that returns its name and a static member function
 * that creates a random Potion, similar to the getRandomMonster() function.
 *
 * In the Player class, add a drinkPotion() member function that applies the
 * potion's effect.
 *
*/
#include <iostream>
#include <string>
#include <string_view> // Requires C++17
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <random> // for std::m19937

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
//int getRandomNumber(int min, int max)
//{
//    // static used for efficiency, so we only calculate this value once
//    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
//
//    // evenly distribute this random number across our range
//    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
//}

// Generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max)
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
    static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    // Set up the distribution (inclusive both ends)
	std::uniform_int_distribution die{ min, max };
	return die(mersenne); // Generate random number
}

class Potion
{
public:
    enum class Type
    {
        HEALTH,
        STRENGTH,
        POSION,

        MAX_TYPES
    };

    enum class Size
    {
        SMALL,
        MEDIUM,
        LARGE,

        MAX_SIZES
    };

private:
    Type m_type{};
    Size m_size{};

public:
    Potion(Type type, Size size)
        : m_type{ type }, m_size{ size }
    {
    }

    static Potion getRandomPotion()
    {
        Type type{ static_cast<Type>(getRandomNumber(0, static_cast<int>(Type::MAX_TYPES) - 1)) };
        Size size{ static_cast<Size>(getRandomNumber(0, static_cast<int>(Size::MAX_SIZES) - 1)) };
        return Potion{ type, size };
    }

    std::string& getTypeName()
    {
        static std::array<std::string, static_cast<std::size_t>(Type::MAX_TYPES)> types
        {
            "Health",
            "Strength",
            "Poison"
        };

        return types.at(static_cast<std::size_t>(m_type));
    }

    std::string& getSizeName()
    {
        static std::array<std::string, static_cast<std::size_t>(Size::MAX_SIZES)> sizes
        {
            "Small",
            "Medium",
            "Large"
        };

        return sizes.at(static_cast<std::size_t>(m_size));
    }

    std::string getName()
    {
        return  getSizeName() + " potion of " + getTypeName();
    }

    Type getType() { return m_type; }
    Size getSize() { return m_size; }
};

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:

    Creature(const std::string_view name, char symbol, int health, int damage, int gold)
        : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }
    {
    }

    const std::string& getName() { return m_name; }
    char getSymbol() { return m_symbol; }
    int getHealth() { return m_health; }
    int getDamage() { return m_damage; }
    int getGold() { return m_gold; }

    void reduceHealth(int amount) { m_health -= amount; }
    void increaseHealth(int amount) { m_health += amount; }
    void increaseDamage(int amount) { m_damage += amount; }
    bool isDead() { return (m_health <= 0); }
    void addGold(int amount) { m_gold += amount; }
};

class Player: public Creature
{
private:
    int m_level{ 1 };

public:
    Player(std::string_view name)
        : Creature{ name, '@', 10, 1, 0 }
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() { return m_level; }
    bool hasWon() { return m_level >= 20; }

    void drinkPotion(Potion& potion)
    {
        // Potencies of potion effects, based on size
        static std::array healthPotencies{ 2, 2, 5 };
        static std::array strengthPotencies{ 1, 1, 1 };
        static std::array poisonPotencies{ 1, 1, 1 };

        switch (potion.getType())
        {
            case Potion::Type::HEALTH:
                increaseHealth(
                    healthPotencies.at(static_cast<std::size_t>(potion.getSize())));
                break;
            case Potion::Type::STRENGTH:
                increaseDamage(
                    strengthPotencies.at(static_cast<std::size_t>(potion.getSize())));
                    break;
            case Potion::Type::POSION:
                reduceHealth(
                    poisonPotencies.at(static_cast<std::size_t>(potion.getSize())));
                break;
            default:
                ; // Drinking a potion of unknown type does nothing
        }
    }
};

class Monster: public Creature
{
public:
    enum class Type
    {
        DRAGON,
        ORC,
        SLIME,

        MAX_TYPES
    };

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::MAX_TYPES)> monsterData
        {
            {
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster( Type type )
        : Creature{ getDefaultCreature(type) }
    {
    }

    static Monster getRandomMonster()
    {
        int randomIndex{ getRandomNumber(0, static_cast<int>(Type::MAX_TYPES) - 1) };
        return Monster{ static_cast<Type>(randomIndex) };
    }
};

// Listing MA
//int main()
//{
//    Creature o{ "orc", 'o', 4, 2, 10};
//    o.addGold(5);
//    o.reduceHealth(1);
//    std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
//
//    return 0;
//}

// For part b)
//int main()
//{
//    std::cout << "Enter your name: ";
//    std::string name{};
//    std::cin >> name;
//
//    std::cout << "Welcome, " << name << ".\n";
//
//    Player p{name};
//    std::cout << "You have " << p.getHealth() << " health "
//                 "and are carrying " << p.getGold() << " gold.\n";
//
//    return 0;
//}

// Listing MD
//#include <iostream>
//#include <string>
//
//int main()
//{
//    Monster m{ Monster::Type::ORC };
//    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
//
//    return 0;
//}

// Listing ME
//int main()
//{
//    // set initial seed value to system clock
//    std::srand(static_cast<unsigned int>(std::time(nullptr)));
//    std::rand(); // get rid of first result
//
//    for (int i{ 0 }; i < 10; ++i)
//    {
//        Monster m{ Monster::getRandomMonster() };
//        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
//    }
//
//    return 0;
//}

// For part f)

// Returns true if successfully receives a potion, false otw
bool rollForPotion()
{
    // 30% chance of getting a potion
    return (getRandomNumber(1, 10) <= 3);
}

// Returns true if successfully escapes, false otw
bool rollForEscape()
{
    // 50% chance to escape
    return (getRandomNumber(0, 1) == 0);
}

// Returns true if the player inputs 'y' or 'Y', false otherwise
bool respondsYes()
{
    char response{};
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void attackMonster(Player &player, Monster &monster)
{

    // If the player is dead, no damage is done
    if (player.isDead())
        return;

    // Attack the monster
    int damage{ player.getDamage() };

    monster.reduceHealth(damage);
    std::cout << "You hit the " << monster.getName() << " for " << damage << " damage.\n";

    // If the monster dies, several things happen
    if (monster.isDead())
    {
        // Report
        std::cout << "You killed the " << monster.getName() << ".\n";

        // Update player stats
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());

        // Roll for a random potion
        if (rollForPotion())
        {
            // Got a potion!
            std::cout << "You got a mythical potion! Would you like to drink it? [y/n]: ";
            if (respondsYes())
            {
                Potion potion{ Potion::getRandomPotion() };
                player.drinkPotion(potion);

                std::cout << "You drank a " << potion.getName() << ".\n";
            }
        }
    }
}

void attackPlayer(Player &player, Monster &monster)
{
    // If the monster is dead, no damage is done
    if (monster.isDead())
        return;

    // Monster attacks the player
    int damage{ monster.getDamage() };

    player.reduceHealth(damage);
    std::cout << "The " << monster.getName() << " hit you for " << damage << " damage.\n";
}

void fightMonster(Player& player, Monster& monster)
{
    // Print encounter message
    std::cout << "You've encountered a " << monster.getName()
              << '(' << monster.getSymbol() << ").\n";

    // Keep fighting while neither the player nor monster are dead
    while (!player.isDead() && !monster.isDead())
    {
        // Ask the user if they want to run or fight
        char response{};
        std::cout << "(R)un or (F)ight: ";
        std::cin >> response;

        if (response == 'f' || response == 'F')
        {
            // Player Wants to fight -- gets to attack first
            // Note: If the attacking party is dead, no damage dealt
            attackMonster(player, monster);
            attackPlayer(player, monster);
        }

        if (response == 'r' || response == 'R')
        {
            // Attempt the escape (50% chance of success)
            if (!rollForEscape())
            {
                std::cout << "You failed to flee!\n";
                // Failed to escape -- Monster attacks!
                attackPlayer(player, monster);
            }
            else
            {
                // Player escapes successfully, end the encounter
                std::cout << "You successfully fled.\n";
                return;
            }
        }
    }
}

int main()
{
    // Create the player
    std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;

    std::cout << "Welcome, " << playerName << '\n';

    Player player{playerName};

    // The game runs while the player hasn't died or reached lvl 20
    while (!player.hasWon() && !player.isDead())
    {
        // Spawn a monster
        Monster monster{ Monster::getRandomMonster() };
        // Begin the fight
        fightMonster(player, monster);
    }

    // Either the player has died or they won the game
    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel()
                  << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "*** Congratulations! You won the game with "
                  << player.getGold() << " gold! ***\n";
    }

    return 0;
}
