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

// Listing M
int main()
{
    Apple a{ "red" };
    Banana b{};

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;
}