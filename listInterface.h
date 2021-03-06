//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_LISTINTERFACE_H
#define DATASTRUCTS_LISTINTERFACE_H
#include <iostream>
#include <cassert>
using namespace std;

/*
the declaration for the abstract class list
makes the constructor and the overloading of the assignment operator private
a full feature implementation should support
copying and assigning list objects
*/
template <typename E>
class List { // List ADT
private:
    void operator =(const List&) {} // Protect assignment
    List(const List&) = default; // Protect copy constructor
public:
    List() = default; // Default constructor
    virtual ~List() = default; // Base destructor
// Clear contents from the list, to make it empty.
    virtual void clear() = 0;
// Insert an element at the current location.
// item: The element to be inserted
    virtual void insert(const E& item) = 0;
// Append an element at the end of the list.
// item: The element to be appended.
    virtual void append(const E& item) = 0;
// Remove and return the current element.
// Return: the element that was removed.
    virtual E remove() = 0;
// Set the current position to the start of the list
    virtual void moveToStart() = 0;
// Set the current position to the end of the list
    virtual void moveToEnd() = 0;
// Move the current position one step left. No change
// if already at beginning.
    virtual void prev() = 0;
// Move the current position one step right. No change
// if already at end.
    virtual void next() = 0;
// Return: The number of elements in the list.
    virtual int length() const = 0;
// Return: The position of the current element.
    virtual int currPos() const = 0;
// Set current position.
// pos: The position to make current.
    virtual void moveToPos(int pos) = 0;
// Return: The current element.
    virtual const E& getValue() const = 0;
// Sequential search for element.
    virtual int ssearch(const E& it) = 0;
// Binary search for element in iterative.
    virtual double ibsearch(const E& it) = 0;
// Binary search for element in recursive form.
    virtual double rbsearch(const E& it, E l, E r) = 0;
};

#endif //DATASTRUCTS_LISTINTERFACE_H
