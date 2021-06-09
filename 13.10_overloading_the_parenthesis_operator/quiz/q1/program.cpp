/*
 * Write a class that holds a string. Overload operator() to return the
 * substring that starts at the index of the first parameter. The length of the
 * substring should be defined by the second parameter.
 *
 * The following code should run: [Listing M]
 *
 * This should print
 *
 *     world
 *
 * Hint: You can use array indicies to access individual chars within the
 * std::string
 * Hint: You can use operator+= to append something to a string
 *
*/
#include <iostream>
#include <string>
#include <cassert>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(const std::string& string = {})
        : m_string{ string }
        {
        }

    std::string operator()(int start, int length);
};

std::string MyString::operator()(int start, int length)
{
    assert(start >= 0 && (start + length < static_cast<int>(m_string.size())) && "Attempted access of OOB index in MyString::operator(int, int)");

    std::string substr{};
    for (int i{ 0 }; i < length; ++i)
    {
        substr += m_string[static_cast<std::string::size_type>(start + i)];
    }

    return substr;
}

// Listing M
int main()
{
    MyString string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}