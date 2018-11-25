//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_SIMPLESTAT_H
#define DATASTRUCTS_SIMPLESTAT_H

#include <iostream>
#include "listInterface.h"
using namespace std;


/*
the declaration for the abstract class Simple Stat
 */

template <typename E>
class SimpleStat { // SimpleStat ADT
private:
//    void operator =(const SimpleStat&) {} //protect assignment
//    SimpleStat(const SimpleStat&) {} //protect copy assignment
public:
    SimpleStat() = default; // Default constructor
    virtual ~SimpleStat() = default; //default destructor
    //Mode: most frequently occurring value
    virtual const E mode() const = 0;
    //Median: the middle value that separates the lower and upper halves of the data set. If
    // it is an even number of data set we take the we sum up the two middle values and divide
    // it by 2
    virtual const E median() const = 0;
    //Mean: the total or the sum divide by number of data items
    virtual const E mean() const = 0;
    //Standard deviation (SD): A measure of the spread of data point about the mean.
    virtual const E SD() const = 0;

};






#endif //DATASTRUCTS_SIMPLESTAT_H
