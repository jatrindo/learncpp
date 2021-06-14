/*
 * Extra credit:
 *
 * This one is a little more tricky.
 *
 * A floating point number is a number with a decimal where the number of digits
 * after the decimal can be variable. A fixed point number is a number with a
 * fractional component where the number of digits in the fractional portion is
 * fixed.
 *
 * In this quiz, we're going to write a class to implement a fixed point number
 * with two fractional digits (e.g. 12.34, 3.00, or 1278.99). Assume that the
 * range of the class should be -32768.99 to 32767.99, that the fractional
 * component should hold any two digits, that we don't want precision errors,
 * and that we want to conserver space.
 *
 * 4a) What type of member variable(s) do you think we should use to implement
 * our fixed point number with 2 digits after the decimal? (Make sure you read
 * the answer before proceeding with the next questions)
 *
 * 4b) Write a class named FixedPoint2 that implements the recommended solution
 * from the previous question.
 *
 * If either (or both) of the non-fractional and fractional part of the number
 * are negative, the number should be treated as negative.
 *
 * Provide the overloaded operators and constructors required for the following
 * program to run: [Listing B]
 *
 * This program should produce the result:
 *
 *  34.56
 *  -2.08
 *  -2.08
 *  -2.08
 *  -0.05
 *  -0.05
 *
 * Hint: Although it may seem like more work initial, it's helpful to store both
 * the non-fractional and fractional parts of the number with the same sign
 * (e.g. both positive if the number is positive, and both negative if the
 * number is negative). This makes doing math much easier later.
 *
 * Hint: To output your number, first cast it to a double
 *
 * 4c) Now add a constructor that takes a double. The following program should
 * run: [Listing C]
 *
 * This program should produce the result:
 *
 *  0.01
 *  -0.01
 *  5.01
 *  -5.01
 *  107
 *
 * Recommendation: This one will be a bit tricky. Do this one in three steps.
 * First, solve for the cases where teh double parameter is representable
 * directly (cases & b above). Then, update your code to handle the cases where
 * the double parameter has a rouding error (cases c & d). Lastly, handle the
 * edge case where the decimal rounds up to 100 (case e).
 *
 * For all cases:
 *
 * You can move a digit from the right of the decimal to the left of the decimal
 * by multiplying by 10. Multiply by 100 to move two plaxes.
 *
 * For cases a & b:
 *
 * You can get the non-fractional part of a double by static casting the double
 * to an integer. To get the frational part, you can subtract out the base part.
 *
 * For cases c & d:
 *
 * You can round a number (on the left of the decimal) by using the std::round()
 * function (included in header cmath)
 *
 * 4d) Overload operator==, operator>>, operator- (unary), and operator+
 * (binary)
 *
 * The following program should run [Listing D]
 *
 * And produce the output:
 *
 *  true
 *  true
 *  true
 *  true
 *  true
 *  true
 *  true
 *  true
 *  -0.48
 *  0.48
 *  Enter a number: 5.678
 *  You entered: 5.68
 *
 * Hint: Add you two FixedPoint2 together by leveraging the double case, adding
 * the results, and converting back to a FixedPoint2.
 * 
 * Hint: For operator>>, use your double constructor to create an anonymous
 * object of type FixedPoint2, and assign it to you FixedPoint2 function parameter
 *
*/

// Soln to A:
//
// Have a 16-bit signed integer hold the non-fraactional part of the
// number, and a 8-bit signed integer to hold the fractional component

#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath> // for std::round

class FixedPoint2
{
private:
    std::int_least16_t m_base{ 0 };
    std::int_least8_t m_decimal{ 0 };

    // Helper function to check sanity of decimal and base parts, as well as
    // perform any final modifications
    void finalizeConstruction()
    {
        assert(std::abs(m_decimal) < 100
            && "finalizeConstruction - Decimal component not a two digit number" );

        // If either the base or decimal is negative, ensure that both parts
        // get negative signs
        if (m_base < 0 || m_decimal < 0)
        {
            m_base = -std::abs(m_base);
            m_decimal = -std::abs(m_decimal);
        }

    }


public:
    FixedPoint2(std::int_least16_t base=0, std::int_least8_t decimal=0)
        : m_base{ base }, m_decimal{ decimal }
    {
        finalizeConstruction();
    }

    FixedPoint2(double d):
        m_base{ static_cast<std::int_least16_t>(std::round(d * 100) / 100) },
        m_decimal{ static_cast<std::int_least8_t>(std::round(d * 100) - m_base * 100) }
    {
        finalizeConstruction();
    }

    operator double() const
    {
        return m_base + (static_cast<double>(m_decimal) / 100);
    }
};

// We take advantage of the double cast so operator<< doesn't need direct
// access to the internals of the FixedPoint2 class -- nice!
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
    out << static_cast<double>(fp);
    return out;
}

// Listing B
//int main()
//{
//    FixedPoint2 a{ 34, 56 };
//    std::cout << a << '\n';
//
//    FixedPoint2 b{ -2, 8 };
//    std::cout << b << '\n';
//
//    FixedPoint2 c{ 2, -8 };
//    std::cout << c << '\n';
//
//    FixedPoint2 d{ -2, -8 };
//    std::cout << d << '\n';
//
//    FixedPoint2 e{ 0, -5 };
//    std::cout << e << '\n';
//
//    std::cout << static_cast<double>(e) << '\n';
//
//    return 0;
//}

// Listing C
int main()
{
    // Handle cases where the argument is representable directly
    FixedPoint2 a{ 0.01 };
    std::cout << a << '\n';

    FixedPoint2 b{ -0.01 };
    std::cout << b << '\n';

    // Handle cases where teh argument has some rounding error
    FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
    std::cout << c << '\n';

    FixedPoint2 d{ -5.01 }; //  stored as -5.0099999... so we'll need to round this
    std::cout << d << '\n';

    // Hnadle case where the argument's decimal rounds to 100 (need to increase base by 1)
    FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
    std::cout << e << '\n';

    return 0;
}

// Listing D
//void testAddition()
//{
//    // h/t to reader Sharjeel Safdar for this function
//    std::cout << std::boolalpha;
//    std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';    // both positive, no decimal overflow
//    std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';    // both positive, with decimal overflow
//    std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n'; // both negative, no decimal overflow
//    std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n'; // both negative, with decimal overflow
//    std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';  // second negative, no decimal overflow
//    std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';  // second negative, possible decimal overflow
//    std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';   // first negative, no decimal overflow
//    std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';   // first negative, possible decimal overflow
//}
//
//int main()
//{
//    testAddition();
//
//    FixedPoint2 a{-0.48};
//    std::cout << a << '\n';
//
//    std::cout << -a << '\n';
//
//    std::cout << "Enter a number: "; // enter 5.678
//    std::cin >> a;
//
//    std::cout << "You entered: " << a << '\n';
//
//    return 0;
//}