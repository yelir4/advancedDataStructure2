#include "random.h"
#include <iostream>

using namespace std;
using namespace coen79_lab2;

// coen 79 lab 2a 1/18/23
// FILE: rand_gen.cpp
// CLASS IMPLEMENTED: rand_gen (see rand_gen.h for documentation)

// print numbers function, passed in a random generator, along with amount of numbers to be generated
void printNumbers(rand_gen &r, int num)
{
    for (int i = 0; i < num; i++)
    {
        // print info (seed, etc) and generate the next number
        r.print_info();
        cout << "Next: " << r.next() << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    // first random num gen
    rand_gen rg(1, 40, 725, 729);

    printNumbers(rg, 5);
    
    rg.set_seed(1);
    printNumbers(rg, 5);
    
    rg.set_seed(15);
    printNumbers(rg, 5);

    // second random number gen
    rand_gen rg2(14, 85, 637, 1947);
    
    printNumbers(rg2, 5);
    
    rg2.set_seed(14);
    printNumbers(rg2, 5);

    return 0;
}
