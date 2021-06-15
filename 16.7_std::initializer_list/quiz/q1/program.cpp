/*
 * Using the IntArray class above [Listing A], implement an overloaded
 * assignment operator that takes an initializer list.
 *
 * The following code should run: [Listing M]
 *
 * This should print:
 *
 *  5 4 3 2 1
 *  1 3 5 7 9 11
 *
*/
#include <cassert> // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length)
        : m_length{ length }, m_data{ new int[length] }
    {
    }

    IntArray(std::initializer_list<int> list)
        : IntArray(static_cast<int>(list.size()))
    {
        // Now initialize our array from the list
        int count{ 0 };
        for (auto element: list)
        {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray()
    {
        delete[] m_data;
        // we don need to set m_data to null or m_length to 0 here, since the
        // object will be destroyed immediately after this function anayway
    }

    IntArray(const IntArray&) = delete; // to avoid shallow copies
    IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

    IntArray& operator=(std::initializer_list<int> list)
    {
        // Delete and replace the current data we have
        delete[] m_data;
        m_length = list.size();

        // Then copy in the new list data
        int count{ 0 };
        for (auto element: list)
        {
            m_data[count] = element;
            ++count;
        }

        return *this;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

// Listing M
int main()
{
    IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    array = {1, 3, 5, 7, 9, 11 };

    for (int count{0}; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    return 0;
}