/*
 * Write an Apple class and a Banana class that are derived from a common Fruit class.
 *
 * Fruit should have two members: a name, and a color.
 * 
 * The following program should run: [Listing M]
 * 
 * And produce the result:
 * 
 *  My apple is red.
 *  My banana is yellow.
 * 
 */
#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(const std::string& name, const std::string& color)
        : m_name{ name }, m_color{ color }
    {
    }

    std::string& getName() { return m_name; };
    std::string& getColor() { return m_color; };
};

class Apple: public Fruit
{
public:
    Apple(const std::string& color)
        : Fruit{ "apple", color }
    {
    }
};

class Banana: public Fruit
{
public:
    Banana()
        : Fruit{ "banana", "yellow" }
    {
    }
};

// Listing M
int main()
{
    Apple a{ "red" };
    Banana b{};

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;
}