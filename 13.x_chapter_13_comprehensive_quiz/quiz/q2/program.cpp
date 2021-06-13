/*
 * Write a class named Average that will keep track of the average of all
 * integers passed to it.
 *
 * Use two members: the first one should be type std::int_least32_t, and used to
 * keep track of the sum of all the numbers you've seen so far.
 *
 * The second should be of type std::int_least_8_t, and used to keep track of
 * how many numbers you've seen so far. You can divide them to find your
 * average.
 *
 * 2a) Write all of the functions necessary for the following program to run:
 * [ Listing A ]
 *
 * And produce the result:
 *
 *  4
 *  6
 *  12
 *  6.5
 *  7
 *  7
 *
 * Hint: Remember all 8 bit integers are usually chars, so std::cout treats them
 * accordingly
*/
#include <iostream>
#include <cstdint> // for fixed-width integers

class Average
{
private:
    std::int_least32_t m_sum{ 0 };
    std::int_least8_t m_n{ 0 };

public:
    Average()
    {
    }

    Average& operator+=(int value)
    {
        m_sum += value;
        ++m_n;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

std::ostream &operator<<(std::ostream &out, const Average &avg)
{
    out << (avg.m_sum / static_cast<double>(avg.m_n));
    return out;
}

// [ Listing A]
int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}