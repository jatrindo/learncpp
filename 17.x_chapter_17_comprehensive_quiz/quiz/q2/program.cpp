/*
 * a) Write an Apple class and a Banana class that are derived from a common Fruit class.
 *
 * Fruit should have two members: a name, and a color.
 * 
 * The following program should run: [Listing M1]
 * 
 * And produce the result:
 * 
 *  My apple is red.
 *  My banana is yellow.
 * 
 *
 * b) Add a new class to the prvious program called GrannySmith that inherits from Apple
 *
 * The following program should run: [Listng M2]
 *
 * And produce the result:
 *
 *  My apple is red.
 *  My banana is yellow.
 *  My granny smith apple is green.
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

// Listing M1
//int main()
//{
//    Apple a{ "red" };
//    Banana b{};
//
//    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//
//    return 0;
//}

// Listng M2
int main()
{
    Apple a{ "red " };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
