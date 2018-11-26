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
    void operator =(const ArrayBasedSimpleStat&) {} //protect assignment
    ArrayBasedSimpleStat(const ArrayBasedSimpleStat&) {} //protect copy assignment
public:
    explicit ArrayBasedSimpleStat() = default; // Default constructor
    explicit ArrayBasedSimpleStat(E a) : AList<E>(a){};

    ~ArrayBasedSimpleStat() = default;

    E mode() {
        int init = 1;
        int max = 0;
        int pos = 0;
        int counter = 1;
        int returnValue;
        while (init != AList<E>::length()) {
            int value = AList<E>::getValue();
            AList<E>::next();
            if(value == AList<E>::getValue()) {
                cout << value << endl;
                counter++;
                returnValue = AList<E>::getValue();
                if(counter > max) {
                    max = counter;

                }
            }
            counter = 1;
            init++;
        }
        cout << "return value: " << returnValue << endl;
        return returnValue;
    }

    E median() {
        if(AList<E>::length() % 2 != 0) {
            AList<E>::moveToPos(AList<E>::length()/2);
            return AList<E>::currPos();
        } else {
            int middleLower = AList<E>::getValue(AList<E>::moveToPos(AList<E>::length()-1/2));
            cout << middleLower;
        }

    }

    E mean() {

    }

    E SD() {

    }
};

#endif //DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
