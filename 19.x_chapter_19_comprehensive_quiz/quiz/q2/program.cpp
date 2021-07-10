/*
 * Write a Pair class that allows you to specify separate types for each of the
 * two values in the pair.
 *
 * The following program should work: [Listing M]
 * 
 * and print:
 * 
 *  Pair: 5 6.7
 *  Pair: 2.3 4
 *
*/
#include <iostream>

template <typename T, typename U>
class Pair
{
private:
    T m_x;
    U m_y;

public:
    Pair(const T& x, const U& y)
        : m_x{ x }, m_y{ y }
    {
    }

    const T& first() const { return m_x; }
    const U& second() const { return m_y; }
};

// [Listing M]
int main()
{
    Pair<int, double> p1{5, 6.7};
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2{2.3, 4};
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}