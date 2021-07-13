/*
 * 3) What's wrong with the following code? Update the programs to be best
 * practices compliant.
 * 
 * 3a) [Listing 3A]
 * 3b) [Listing 3B]
*/
// Listing 3A
//#include <iostream>
//#include <memory> // for std::shared_ptr
//
//class Resource
//{
//public:
//    Resource() { std::cout << "Resource acquired\n"; }
//    ~Resource() { std::cout << "Resource destroyed\n"; }
//};
//
//int main()
//{
//    // auto* res{ new Resource{} };
//    // std::shared_ptr<Resource> ptr1{ res };
//    //      ^^^ std::make_shared() should be used instead of these two lines
//
//    // std::shared_ptr<Resource> ptr2{ res }; // <-- The main issue is here
//
//    // Issue Explanation: Two different std::shared_ptr's were created
//    // separately to manage the same resource, rather than using a copy
//    // constructor to initialize the std::shared_ptr with the first. This causes
//    // for a double-free to occur when the main function ends and the second
//    // std::shared_ptr to go out of scope gets destroyed.
//
//    // Solution: Have the second shared pointer be copy-constructed
//    std::shared_ptr<Resource> ptr1{ std::make_shared<Resource>() };
//    std::shared_ptr<Resource> ptr2{ ptr1 };
//
//    return 0;
//}

// Listing 3B
#include <iostream>
#include <memory> // for std::shared_ptr

class Something; // assume Something is a class that can throw an exception

int main()
{
    // doSomething(std::shared_ptr{ new Something{} }, std::shared_ptr{ new Something{} });
    //      ^^^ The main issue is that two std::shared_ptr's are being made directly on
    // objects whose constructors are potentially-throwing.

    // Issue Explanation: Compilers have a lot of leeway on the order of what to
    // evaluate in the above line. There exists a problematic order that, when
    // executed, would cause memory to be leaked.
    //
    // A problematic order would consist of one of the 'new Something{}'
    // expressions being evaluated successfully (dynamically allocating an
    // object), and then the second 'new Something{}' expression being evaluated
    // but throwing an exception, before the std::shared_ptr of the already
    // dynamically allocated Something object is created to manage said object.
    //
    // The exception will cause the above line to abort execution (transferring
    // control flow to the nearest applicable catch() block, if any), and leave
    // us with an allocated-but-not-later-deleted Something object, i.e. a
    // memory leak.

    // Solution: Use std::make_shared() to create the shared pointers, rather
    // than making them directly
    doSomething(std::make_shared<Something>(), std::make_shared<Something>());

    return 0;
}
