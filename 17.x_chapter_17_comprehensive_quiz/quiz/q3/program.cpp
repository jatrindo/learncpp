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

class Creature
{
private:
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
    bool isDead() { return (m_health <= 0); }
    void addGold(int amount) { m_gold += amount; }
};

// Listing MA
int main()
{
    Creature o{ "orc", 'o', 4, 2, 10};
    o.addGold(5);
    o.reduceHealth(1);
    std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

    return 0;
}

// Listing MD
//#include <iostream>
//#include <string>
//
//int main()
//{
//    Monster m{ Monster::Type::orc };
//    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
//
//    return 0;
//}

// Listing ME
//#include <iostream>
//#include <string>
//#include <cstdlib> // for rand() and srand()
//#include <ctime> // for time()
//
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
