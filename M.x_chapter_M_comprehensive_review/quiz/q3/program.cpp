/*
 * 3) What's wrong with the following code? Update the programs to be best
 * practices compliant.
 * 
 * 3a) [Listing 3A]
 * 3b) [Listing 3B]
*/
// Listing 3A
#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto* res{ new Resource{} };
    std::shared_ptr<Resource> ptr1{ res };
    std::shared_ptr<Resource> ptr2{ res };

    return 0;
}

// Listing 3B
//#include <iostream>
//#include <memory> // for std::shared_ptr
//
//class Something; // assume Something is a class that can throw an exception
//
//int main()
//{
//    doSomething(std::shared_ptr{ new Something{} }, std::shared_ptr{ new Something {} });
//
//    return 0;
//}