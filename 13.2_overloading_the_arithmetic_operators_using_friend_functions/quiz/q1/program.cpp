/*
 * Question 1. 
 *
 * a) Write a class named Fraction that has a integer numerator and denominator
 * member. Write a print() function that prints out the fraction.
 *
 * The following code should compile: [Listing A]
 *
 * This should print:
 *
 * 1/4
 * 1/2
 *
 *
 * b) Add overloaded multiplication operators to handle multiplication between a
 * Fraction and integer, and between two Fractions. Use the friend function
 * method.
 *
 * The following code should compile: [Listing B]
 *
 * This should print
 *
 * 2/5
 * 3/8
 * 6/40
 * 4/5
 * 6/8
 * 6/24
 *
 *
 * e) Extra credit: The fraction 2/4 is the same as 1/2, but 2/4 is not reduced
 * to the lowest terms. We can reduce any given fraction to lowest terms by
 * finding the greatest common divisor (GCD) between the numerator and
 * denominator, and the ndividing both the numerator and denominator by the GCD.
 *
 * The following is a function to find the GCD:
 *
 *  int gcd(int a, int b) {
 *      return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b)
 *  }
 *
 * Add this function to your class, and write a member function named reduce()
 * that reduces your function. Make sure all fractions are properly reduced.
 *
 * The following should compile: [Listing E]
 *
 * And produce the result:
 *
 * 2/5
 * 3/8
 * 3/20
 * 4/5
 * 3/4
 * 1/4
 * 0/6
 *
*/
#include <iostream>

class Fraction
{
private:
    int m_num{ 0 };
    int m_den{ 1 };

public:
    Fraction(int num = 0, int den = 1)
        : m_num{ num }, m_den{ den }
    {
    }

    void print()
    {
        std::cout << m_num << '/' << m_den << '\n';
    }

    friend Fraction operator*(const Fraction& frac, int i);
    friend Fraction operator*(int i, const Fraction& frac);
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
};

Fraction operator*(const Fraction &frac, int i)
{
    return Fraction{ frac.m_num * i, frac.m_den };
}

Fraction operator*(int i, const Fraction &frac)
{
    return { frac * i };
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    return Fraction{ frac1.m_num * frac2.m_num, frac1.m_den * frac2.m_den };
}

// Listing A
//int main()
//{
//    Fraction f1{ 1, 4 };
//    f1.print();
//
//    Fraction f2{ 1, 2 };
//    f2.print();
//
//    return 0;
//}

// Listing B
#include <iostream>
 
int main()
{
    Fraction f1{2, 5};
    f1.print();
 
    Fraction f2{3, 8};
    f2.print();
 
    Fraction f3{ f1 * f2 };
    f3.print();
 
    Fraction f4{ f1 * 2 };
    f4.print();
 
    Fraction f5{ 2 * f2 };
    f5.print();
 
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
 
    return 0;
}

// Listing E
// #include <iostream>

// int main()
// {
//     Fraction f1{2, 5};
//     f1.print();

//     Fraction f2{3, 8};
//     f2.print();

//     Fraction f3{f1 * f2};
//     f3.print();

//     Fraction f4{f1 * 2};
//     f4.print();

//     Fraction f5{2 * f2};
//     f5.print();

//     Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
//     f6.print();

//     Fraction f7{0, 6};
//     f7.print();

//     return 0;
// }