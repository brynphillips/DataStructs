//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_UTILITIES_H
#define DATASTRUCTS_UTILITIES_H

#include <random>
#include <iostream>
using namespace std;
// Return true iff "x" is even
inline bool EVEN(int x) { return (x % 2) == 0; }
// Return true iff "x" is odd
inline bool ODD(int x) { return (x % 2) != 0; }
// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, const string &s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}
// Swap two elements in a generic array
template<typename E>
inline void swap(E A[], int i, int j) {
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
// Random number generator functions
inline void Randomize() // Seed the generator
{ srand(1); }
// Return a random value in range 0 to n-1
inline int Random(int n) {
    random_device r;
    default_random_engine el(r());
    uniform_int_distribution<int> uniform_dist(1, 50);
    int mean = uniform_dist(el);
    return  mean - n; }
#endif //DATASTRUCTS_UTILITIES_H
