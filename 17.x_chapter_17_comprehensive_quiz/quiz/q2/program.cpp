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

    const std::string& getName() const { return m_name; };
    const std::string& getColor() const { return m_color; };
};

class Apple: public Fruit
{
public:
    Apple(const std::string& color)
        : Fruit{ "apple", color }
    {
    }

protected: // protected so only derived classes can access
    Apple(const std::string& name, const std::string& color)
        : Fruit{ name, color }
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

class GrannySmith: public Apple
{
public:
    GrannySmith()
        : Apple{ "granny smith apple", "green" }
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
