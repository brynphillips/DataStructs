//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_NODE_H
#define DATASTRUCTS_NODE_H
#include <iostream>
using namespace std;

// Singly linked list node
template <typename E> class LinkNode {
public:
    E element; // Value for this node
    LinkNode *next; // Pointer to next node in list
// Constructors
    explicit LinkNode(const E& elemval, LinkNode* nextval =NULL)
    { element = elemval; next = nextval; }

    explicit LinkNode(LinkNode* nextval =NULL) { next = nextval; }
};
#endif //DATASTRUCTS_NODE_H
