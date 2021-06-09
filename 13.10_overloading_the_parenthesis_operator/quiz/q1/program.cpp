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
*/
int main()
{
    MyString string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}