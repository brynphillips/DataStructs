//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
#define DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
#include "arrayBasedList.h"
#include "simpleStatADT.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

template <typename E>
class ArrayBasedSimpleStat: public AList<E>, public SimpleStat<E> {
private:
    void operator=(const ArrayBasedSimpleStat &) {} //protect assignment
    ArrayBasedSimpleStat(const ArrayBasedSimpleStat &) {} //protect copy assignment
public:
    explicit ArrayBasedSimpleStat() = default; // Default constructor
    explicit ArrayBasedSimpleStat(E a) : AList<E>(a) {};

    ~ArrayBasedSimpleStat() = default;

    E mode() {
        map<E, E> modeMap;
        for (int i = 0; i < AList<E>::length(); ++i) {
            ++modeMap[AList<E>::getValue()];
            AList<E>::next();
        }
        auto x = max_element(modeMap.begin(), modeMap.end(), [](const pair<E, E>& a, const pair<E, E>& b) {
            return a.second < b.second;
        });
//        stack<double> answer;
//        answer.push(x->first);
//        answer.push(x->second);

//        cout << "stack size: " << answer.size() << endl;
//        cout << "Map count: " << modeMap.count(x->second);

//        return answer.top();
        return x->first;
    }

    E median() {
        if (AList<E>::length() % 2 != 0) {
            AList<E>::moveToPos(AList<E>::length() / 2);  // Get the middle position of a odd array list
//            cout << "First" << endl;
            return AList<E>::currPos();
        } else {
            AList<E>::moveToPos((AList<E>::length() - 1) / 2);  //  Get the middle position minus one of even list
            double middleLower = AList<E>::getValue();  //  Set a double equal to the value at that position
//            cout << "Second" << endl; //  testing purposes
//            cout << middleLower;  //
            AList<E>::moveToPos((AList<E>::length()) / 2);    //  Get the value at the middle of the sorted array
            double middleUpper = AList<E>::getValue();      // set a double equal ®to that value
            return (middleLower + middleUpper) / 2.0;         // add them together and divide by two
        }

    }

    E mean() {
        AList<E>::moveToStart();
        double sum = 0.0;   //create a value for the sum
        for (int i = 0; i < AList<E>::length(); ++i) { //iterate through the values
            sum += AList<E>::getValue();    // add all current value to the sum
            AList<E>::next();   //for to the next value;
        }
        return sum / AList<E>::length();
    }

    E SD() {
        float SD = 0.0;
        double mean = ArrayBasedSimpleStat::mean(); //gets the mean of the values
        AList<E>::moveToStart();    //move the current element to the start
//        cout << "mean: " << mean << endl; //testing to make sure I'm getting the correct mean.
        for (int i = 0; i < AList<E>::length(); ++i) { //iterate through the array
            SD += (pow((AList<E>::getValue() - mean), 2)); //set SD to the of the value minus the mean to the second
            AList<E>::next();                              //power, then go to the next element.
        }
        double result = sqrt(SD / AList<E>::length());  //the result is the square root of the SD divided by the number
        return result;                                  //of elements.
    };

};
#endif //DATASTRUCTS_ARRAYBASEDSIMPLESTAT_H
