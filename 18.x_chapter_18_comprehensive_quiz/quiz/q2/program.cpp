/*
 *
 * 2a) Create an abstract class named Shape.
 *
 * This class should have three functions: a pure virtual function that takes
 * and returns a std::ostream, an overloaded operator<< and an empty virtual
 * destructor
 *
 *
 * 2b) Derive two classes from Shape: a Triangle, and a Circle.
 *
 * The Triangle should have 3 Points as members. The Circle should have one
 * center point, and an integer radius. Overload the print() function so that
 * following program runs: [Listing B]
 *
 * This should print:
 *
 *  Circle(Point(1, 2, 3), radius 7)
 *  Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))
 *
 * Here's a point class you can use: [Listing BP]
 *
 *
 * 2c) Given the above classes (Point, Shape, Circle, and Triangle), finish the
 * following program: [Listing C]
 */
#include <iostream>
#include <vector>


class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() {}
};

// Listing BP
class Point
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    Point(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
        return out;
    }
};

class Triangle: public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {
    }

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
        return out;
    }
};

class Circle: public Shape
{
private:
    Point m_center;
    int m_radius;

public:
    Circle(const Point& center, int radius)
        : m_center{ center }, m_radius{ radius }
    {
    }

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ')';
        return out;
    }

    int getRadius() const { return m_radius; }
};

// Listing B
//int main()
//{
//    Circle c{ Point{ 1, 2, 3}, 7 };
//    std::cout << c << '\n';
//
//    Triangle t{ Point{ 1, 2, 3}, Point{ 4, 5, 6}, Point{ 7, 8, 9}};
//    std::cout << t << '\n';
//
//    return 0;
//}

int getLargestRadius(std::vector<Shape*> v)
{
    int largest{};
    for (const auto* shape: v)
    {
        const Circle *c{ dynamic_cast<const Circle *>(shape) };
        if (c != nullptr)
        {
            if (c->getRadius() > largest)
            {
                largest = c->getRadius();
            }
        }
    }
    return largest;
}

// Listing C
int main()
{
    std::vector<Shape*> v{
        new Circle{ Point{1, 2, 3}, 7},
        new Triangle{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Circle{ Point{4, 5, 6}, 3}
    };

    // print each shape in vector v on its own line here
    for (const auto* shape: v)
    {
        std::cout << *shape << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this functiion

    // delete each element in the vector here
    for (const auto* shape: v)
    {
        delete shape;
    }

    return 0;
}
