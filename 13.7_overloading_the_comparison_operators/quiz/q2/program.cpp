/*
 * Add an overloaded operator<< and operator< to the Car class at the top of the
 * lesson [Listng A] so that the following program compiles [Listing M]
 *
 * This program should produce the following output:
 *  (Honda, Accord)
 *  (Honda, Civic)
 *  (Toyota, Camry)
 *  (Toyota, Corolla)
 *
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Listing A
class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string &make, const std::string &model)
        : m_make{make}, m_model{model}
    {
    }

    friend bool operator==(const Car& c1, const Car& c2);
    friend bool operator!=(const Car& c1, const Car& c2);
};

bool operator==(const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make
            && c1.m_model == c2.m_model);
}

bool operator!=(const Car& c1, const Car& c2)
{
    return !(c1 == c2);
}

// Listing M
int main()
{
    std::vector<Car> cars{
        {"Toyota", "Corolla"},
        {"Honda", "Accord"},
        {"Toyota", "Camry"},
        {"Honda", "Civic"},
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto &car : cars)
        std::cout << car << '\n'; // requires an overloaded operator <<

    return 0;
}