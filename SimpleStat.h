//
// Created by Bryn Phillips on 11/25/18.
//

#ifndef DATASTRUCTS_SIMPLESTATARRAY_H
#define DATASTRUCTS_SIMPLESTATARRAY_H

#include "simpleStatADT.h"
#include "iostream"

using namespace std;

template <typename E>
class SimpleStatArray: public SimpleStat<E> { // SimpleStat ADT
private:
//    void operator =(const SimpleStat&) {} //protect assignment
//    SimpleStat(const SimpleStat&) {} //protect copy assignment
public:
//    SimpleStat() = default; // Default constructor
//    virtual ~SimpleStat() = default; //default destructor
//    //Mode: most frequently occurring value
//    virtual const E mode() const = 0;
//    //Median: the middle value that separates the lower and upper halves of the data set. If
//    // it is an even number of data set we take the we sum up the two middle values and divide
//    // it by 2
//    virtual const E median() const = 0;
//    //Mean: the total or the sum divide by number of data items
//    virtual const E mean() const = 0;
//    //Standard deviation (SD): A measure of the spread of data point about the mean.
//    virtual const E SD() const = 0;

};

#endif //DATASTRUCTS_SIMPLESTATARRAY_H
