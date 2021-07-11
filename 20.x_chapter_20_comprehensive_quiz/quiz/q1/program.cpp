/*
 * Write a Fraction class that has a constructor that takes a numerator and a
 * denominator.
 *
 * If the user passes in a denominator of 0, throw an exception of type
 * std::runtime_error (included in the stdexcept header).
 *
 * In your main program, ask the user to enter two integers. If the Fraction is
 * valid, print the fraction. If the Fraction is invalid, catch a
 * std::exception, and tell the user that they entered an invalid fraction.
 *
 * Here's what one run of the program should output:
 * 
 *  Enter the numerator: 5
 *  Enter the deonminator: 0
 *  Invalid denominator
 *
*/
#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_top;
    int m_bot;

public:
    Fraction(int top, int bot)
        : m_top{ top }, m_bot{ bot }
    {
        if (bot == 0)
            throw std::runtime_error("Invalid denominator");
    }

    friend std::ostream& operator<<(std::ostream& out, Fraction& f)
    {
        std::cout << f.m_top << '/' << f.m_bot;
        return out;
    }
};

int main()
{
    // Ask two integers:
    std::cout << "Enter the numerator: ";
    int numerator;
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    int denominator;
    std::cin >> denominator;

    try
    {
        Fraction f{ numerator, denominator };
        std::cout << f << '\n';
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
