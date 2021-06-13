/*
 * Write your own integer array class named intArray from scratch (do not use
 * std::array or std::vector).
 *
 * Users should pass in the size of the array when it is created, and the array
 * should be dynamically allocated. Use assert statements to guard against bad
 * data.
 *
 * Create any constructors or overloaded operators needed to make the following
 * program operate correctly: [ Listing M ]
 *
 * This program should print:
 * 
 *  5 8 2 3 6
 *  5 8 2 3 6
 *
*/

// Listing M
#include <iostream>
#include <cassert>

class IntArray
{
private:
    int m_length{ 0 };
    int* m_array{ nullptr };

public:
    explicit IntArray(int length)
        : m_length{ length }
    {
        assert(length > 0 && "IntArray() - Non-positive intial length given");

        m_array = new int[m_length]{};
    }

    IntArray(const IntArray& intarr)
        : m_length{ intarr.m_length }
    {
        assert(intarr.m_length >= 0 && "IntArray(const IntArray&) -"
            " IntArray attempted to be constructed with IntArray of non-positive length");

        // Initialize member length and pointer
        m_array = new int[m_length];

        // Copy the parameter's array into the new array
        for (int i{ 0 }; i < m_length; ++i)
        {
            m_array[i] = intarr.m_array[i];
        }
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    int& operator[](const int i)
    {
        assert( i >= 0 && i < m_length && "IntArray::operator[] - Invalid index given");
        return m_array[i];
    }

    IntArray& operator=(const IntArray& intarr)
    {
        // Self-assignment guard
        if (&intarr == this)
            return *this;

        assert(intarr.m_length >= 0 && "IntArray::operator= -"
            " IntArray with non-positive length attribute attempted to be assigned");

        // Delete the previous array we have to prevent memory leakage
        delete[] m_array;

        // Update length and pointer
        m_length = intarr.m_length;
        m_array = new int[m_length];

        // Copy the parameter's array into the new array
        for (int i{ 0 }; i < m_length; ++i)
        {
            m_array[i] = intarr.m_array[i];
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr)
    {
        for (int i{ 0 }; i < arr.m_length; ++i)
        {
            out << arr.m_array[i] << ' ';
        }
        return out;
    }
};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto &ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}