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

// Listing BP
//class Point
//{
//private:
//    int m_x{};
//    int m_y{};
//    int m_z{};
//
//public:
//    Point(int x, int y, int z)
//        : m_x{x}, m_y{y}, m_z{z}
//    {
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Point& p)
//    {
//        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
//        return out;
//    }
//}

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

// Listing C
//#include <vector>
//#include <iostream>
//
//int main()
//{
//    std::vector<Shape*> v{
//        new Circle{ Point{1, 2, 3}, 7},
//        new Triangle{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
//        new Circle{ Point{4, 5, 6}, 3}
//    };
//
//    // print each shape in vector v on its own line here
//
//    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this functiion
//
//    // delee each element in the vector here
//
//    return 0;
//}