/*
 * Write a Pair class that allows you to specify separate types for each of the
 * two values in the pair.
 *
 * The following program should work: [Listing M]
 * 
 * and print:
 * 
 *  Pair: 5 6.7
 *  Pair: 2.3 4
 *
*/
// [Listing M]
int main()
{
    Pair<int, double> p1{5, 6.7};
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair<double, int> p2{2.3, 4};
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}