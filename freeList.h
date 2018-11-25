//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_FREELIST_H
#define DATASTRUCTS_FREELIST_H

#include <iostream>

template <typename E> class Link {
private:
    static Link<E>* freelist; // Reference to freelist head
public:
    E element; // Value for this node
    Link* next; // Point to next node in list
// Constructors
    explicit Link(const E& elemval, Link* nextval =NULL)
    { element = elemval; next = nextval; }

    explicit Link(Link* nextval =NULL) { next = nextval; }

    void* operator new(size_t) { // Overloaded new operator
        if (freelist == NULL) return ::new Link; // Create space
        Link<E>* temp = freelist; // Can take from freelist
        freelist = freelist->next;
        return temp; // Return the link
    }
// Overloaded delete operator
    void operator delete(void* ptr) {
        ((Link<E>*)ptr)->next = freelist; // Put on freelist
        freelist = (Link<E>*)ptr;
    }
};
// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;

#endif //DATASTRUCTS_FREELIST_H
