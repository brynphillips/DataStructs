//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
#define DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
#include "arrayBasedList.h"
#include "simpleStatADT.h"

using namespace std;

template <typename E>
class ArrayBasedSimpleStat: public AList<E>, public SimpleStat<E> {
private:
//    void operator =(const ArrayBasedSimpleStat&) {} //protect assignment
//    ArrayBasedSimpleStat(const ArrayBasedSimpleStat&) {} //protect copy assignment
public:
//    ArrayBasedSimpleStat() = default; // Default constructor
//    ~ArrayBasedSimpleStat() = default; //default destructor
//    //Mode: most frequently occurring value
//    const E mode() {
//        for(auto i: AList<E>::listSize) {
//            cout << AList<E>::getValue();
//        }
//    }
//
//    //Median: the middle value that separates the lower and upper halves of the data set. If
//    // it is an even number of data set we take the we sum up the two middle values and divide
//    // it by 2
//    virtual const E median() const = 0;
//    //Mean: the total or the sum divide by number of data items
//    virtual const E mean() const = 0;
//    //Standard deviation (SD): A measure of the spread of data point about the mean.
//    virtual const E SD() const = 0;
};

#endif //DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
