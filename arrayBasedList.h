//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_ARRAYBASEDLIST_H
#define DATASTRUCTS_ARRAYBASEDLIST_H
#include "listInterface.h"
#include "utilities.h"

template <typename E> // Array-based list implementation
class AList : public List<E> {
private:
    int maxSize; // Maximum size of list
    int listSize; // Number of list items now
    int curr; // Position of current element
    E* listArray; // Array holding list elements
public:

/*
defaultSize is an optional parameter, if no paramenter is given to the array, defaultSize will be the assumed constant value
*/
    explicit AList(int size) { // Constructor
        maxSize = size;
        listSize = curr = 0;//head of the list starts at position 0
        listArray = new E[maxSize];
    }
    ~AList() { delete [] listArray; } // Destructor
    void clear() { // Reinitialize the list
        delete [] listArray; // Remove the array
        listSize = curr = 0; // Reset the size
        listArray = new E[maxSize]; // Recreate array
    }
// Insert "it" at current position O(1) at tail
    void insert(const E& it) {
        Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--) // Shift elements up
            listArray[i] = listArray[i-1]; // to make room
        listArray[curr] = it;
        listSize++; // Increment list size
    }
    void append(const E& it) { // Append "it" O(1)
        Assert(listSize < maxSize, "List capacity exceeded");
        listArray[listSize++] = it;
    }
// Remove and return the current element. O(1) at tail
    E remove() {
        Assert((curr>=0) && (curr < listSize), "No element");
        E it = listArray[curr]; // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }
    void moveToStart() { curr = 0; } // Reset position
    void moveToEnd() { curr = listSize; } // Set at end
    void prev() { if (curr != 0) curr--; } // Back up
    void next() { if (curr < listSize) curr++; } // Next
// Return list size
    int length() const { return listSize; }
// Return current position
    int currPos() const { return curr; }
// Set current list position to "pos" O(1)
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
        curr = pos;
    }
    const E& getValue() const { // Return current element O(1)
        Assert((curr>=0)&&(curr<listSize),"No current element");
        return listArray[curr];
    }

    int ssearch (const E& it) {
        for (AList<E>::moveToStart(); AList<E>::currPos()<AList<E>::length();AList<E>::next()) { //for loop for iteration
            cout << AList<E>::currPos() << ": " << AList<E>::getValue()<< endl; //testing purposes
            if(AList<E>::getValue() == it) {    //compare value
                return AList<E>::currPos();     //return the position of that value.
            }
        }
        return -1;
    }

    double ibsearch(const E& it) {
        double begin = -1;  //set the beginning
        double ending = length();   //set the ending
        while (begin +1 != ending) {    //while the beginning != ending
//            cout << "begin: " << begin << endl; // testing
//            cout << "ending: " << ending << endl; // testing
            double i = (begin+ending)/2;    // set the position to the middle
            cout << "i: " << i << endl;
            moveToPos(i);   //go to that position
            if (it < getValue()) { //check to see if smaller then the value at that position
                ending = i;         // if it is then set the ending at that position
            }
            if (it == getValue()) { //if it's equal then return that position
                return i;
            }
            if (it > getValue()) { //if the value is bigger then set the beginning to that position
                begin = i;
            }
        }
        return -1; //return -1 if not found.
    }
    //****Get this working****
//    double rbsearch(const E& it, E& l, E& r) {
////        int begin = -1;  //set the beginning
////        int ending = length();   //set the ending
//        if (r >= 1) {
//            double mid = (begin+(r - 1)) / 2;
//            moveToPos(mid);
//            if(getValue() == it) {
//                return mid;
//            }
//            if(getValue() > it) {
//                mid - 1;
//                return rbsearch(it, l, mid-1);
//            }
//            return rbsearch(it, mid+1, r);
//        }
//    }
//};
#endif //DATASTRUCTS_ARRAYBASEDLIST_H
