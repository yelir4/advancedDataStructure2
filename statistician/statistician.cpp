// coen 79 lab 2a 1/18/23
// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "statistician.h"

using namespace std;

namespace coen79_lab2
{
	// constructor O(1)
    // initialize member variables' values
	statistician::statistician( )
    {
        total = size = 0;
    }
    
    // next function O(1)
    // parameter r: to add to statistician
    // add r to total and increment statistician size
    void statistician::next(double r)
    {
        total += r;
        size++;

        if(size == 1) { // if r is first number in statistician, set min, max, avg to r
            min = max = avg = r;
        } else {    // otherwise compare to current min max avg values, update average
            if(r < min) {
                min = r;
            } else if(r > max) {
                max = r;
            }
            avg = total / size;
        }
    }
    
    // reset function O(1)
    // reinitialize variables (reset statistician)
    void statistician::reset( )
    {
        total = size = 0;
    }

    // mean() function O(1)
    // precondition: sequence is not empty
    // return average value in statistician
    double statistician::mean( ) const
    {
        assert(size != 0);
        return avg;
    }
    
    // minimum() function O(1)
    // precondition: sequence is not empty
    // return minimum value in statistician
    double statistician::minimum( ) const
    {
        assert(size != 0);
        return min;
    }
    
    // maximum() function O(1)
    // precondition: sequence is not empty
    // return maximum value in statistician
    double statistician::maximum( ) const
    {
        assert(size != 0);
        return max;
    }
    
    // FRIEND + operator O(1)
    // precondition: neither statistician may be empty
    // parameters: s1, s2 statisticians to add together
    // returns statistician object which adds values in s1, s2
    statistician operator +(const statistician& s1, const statistician& s2)
    {
        assert(s1.size != 0);
        assert(s2.size != 0);
        statistician s0;

        s0.size = s1.length() + s2.length(); // combine values and assign to returning object
        s0.total = s1.sum() + s2.sum();
        s0.min = (s1.minimum() < s2.minimum() ? s1.minimum() : s2.minimum());
        s0.max = (s1.maximum() > s2.maximum() ? s1.maximum() : s2.maximum());
        s0.avg = ((s1.mean() * s1.length()) + (s2.mean() * s2.length())) / s0.size;

        return s0; // return the new statistician object with proper values
    }
    
    // == non member operator O(1)
    // parameters: s1, s2 statisticians to compare equality
    // return true if both statisticians are empty or if all values match
    // otherwise, if only one statistician is empty or if the values do not match return false
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.length() == 0 || s2.length() == 0) {
            return(s1.length() == s2.length());
        } else {
            if(s1.length() != s2.length()) return false;
            if(s1.sum() != s2.sum()) return false;
            if(s1.minimum() != s2.minimum()) return false;
            if(s1.maximum() != s2.maximum()) return false;
            if(s1.mean() == s2.mean()) return true; // compare necessary values, return true if all match
        }
    }
    
    // * friend operator O(1)
    // precondition: p cannot be empty
    // parameter: scale scalar to multiply values in statistician 'p' by
    // return scaled statistician
    statistician operator *(double scale, const statistician& p)
    {
        assert(p.length() != 0);
        statistician s0;
        if(scale > 0) { // if scale positive, simply scale min and max
            s0.min = p.minimum() * scale;
            s0.max = p.maximum() * scale;
        } else { // scale negative, must swap min and max
            double temp;
            temp = p.minimum() * scale;
            s0.min = p.maximum() * scale;
            s0.max = temp;
        }

        s0.total = p.sum() * scale; // initialize variables of statistician to return
        s0.avg = p.mean() * scale;
        s0.size = p.length();
        return s0;
    }
}