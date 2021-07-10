/*
 * A string-value pair is a special type of pair where the first value is always
 * a string type, and the second value can be any type.
 *
 * Write a template class named StringValuePair that inherits from a partially
 * specialized Pair class (using std::string as the first type, and allowing the
 * user to specify the second type).
 * 
 * The following program should run: [List M]
 *
 * and print:
 * 
 *  Pair: Hello 5
*/
#include <iostream>
#include <string>

// Pair class from Q2:
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

template <typename U>
class StringValuePair: public Pair<std::string, U>
{
public:
    StringValuePair(const std::string& x, const U& y)
        : Pair<std::string, U>{ x, y }
    {
    }
};

// [Listing M]
int main()
{
    StringValuePair<int> svp{ "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}