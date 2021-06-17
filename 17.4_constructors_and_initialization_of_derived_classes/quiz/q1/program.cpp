/*
 * Create a Fruit base class that contains two private members: a name
 * (std::string), and a color (std::string).
 *
 * Create an Apple class that inherits Fruit. Apple should have an additional
 * private member: fiber (double). Create a Banana class that also inherits
 * Fruit. Banana has no additional members.
 *
 * The following program should run: [Listing M]
 *
 * And print the following:
 *
 *  Apple(Red delicious, red, 4.2)
 *  Banana(Cavendish, yellow)
 * 
*/

// Listing M
int main()
{

    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}