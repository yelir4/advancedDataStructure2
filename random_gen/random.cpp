// coen 79 lab 2a 1/18/23
// FILE: rand_gen.cpp
// CLASS IMPLEMENTED: rand_gen (see rand_gen.h for documentation)

#include "random.h"
// including the random header file

namespace coen79_lab2
{    
    // constructor O(1)
    // precondition: modulus != 0
    // initialize random number generator
    rand_gen::rand_gen(int seed, int multiplier, int increment, int modulus) {
        assert(modulus != 0);
        this->seed = seed;
        this->multiplier = multiplier;
        this->increment = increment;
        this->modulus = modulus;
    }
    
    // set_seed() function O(1)
    // update seed with new seed value
    void rand_gen::set_seed(int new_seed) {
        seed = new_seed;
    }
    
    // next() function O(1)
    // set and return new seed
    int rand_gen::next() {
        int i = (multiplier * seed + increment) % modulus;
        set_seed(i);
        return i;
    }
    
    // print_info() function O(1)
    // print out values for the user
    void rand_gen::print_info() {
        cout << "Seed: " << seed << endl;
        cout << "Multiplier: " << multiplier << endl;
        cout << "Increment: " << increment << endl;
        cout << "Modulus: " << modulus << endl;
    }
}
