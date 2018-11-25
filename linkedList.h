//
// Created by doe2 on 11/24/2018.
//

#ifndef DATASTRUCTS_LINKEDLIST_H
#define DATASTRUCTS_LINKEDLIST_H
//#include "Node.h"
#include "freeList.h"
#include "ListInterface.h"
//#include <cassert>
#include "utilities.h"

/*
A linked list is made up of a series of objects, called the nodes of the list.
 list node is a distinct object (as opposed to simply a cell in an array), it is
good practice to make a separate list node class
it also makes it reusable to other code in a more practical way.
*/

// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list
    void init() { // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    void removeall() { // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList(int size) { init(); } // Constructor
    ~LList() { removeall(); } // Destructor
    void print() const; // Print list contents
    void clear() { removeall(); init(); } // Clear list


// Insert "it" at current position
//Inserting a new element is a three-step process. First, the new list node is
//created and the new element is stored into it. Second, the next field of the new
//list node is assigned to point to the current node (the one after the node that curr
//points to). Third, the next field of node pointed to by curr is assigned to point to
//the newly inserted node.
    void insert(const E& it) {
        //new creates the new link node and calls the Link class constructor, which
        //takes two parameters. The first is the element. The second is the value to be placed
        //in the list node’s next field, in this case“curr->next.”
        curr->next = new Link<E>(it, curr->next); //3 step insertion
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }


    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }


// Remove and return current element
//Removing a node from the linked list requires only that the appropriate pointer
//be redirected around the node to be deleted
//temporary
//pointer ltemp is first assigned to point to the node being removed. A call
//to delete is later used to return the old node to free storage
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }


    void moveToStart() // Place curr at list start
    { curr = head; }


    void moveToEnd() // Place curr at list end
    { curr = tail; }


// Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
// March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }


// Move curr one step right; no change if already at end
//Method next simply moves curr one position toward the tail of the list,
//which takes (1) time. Method prev moves curr one position toward the head
//of the list
    void next()
    { if (curr != tail) curr = curr->next; }
    int length() const { return cnt; } // Return length


// Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }


// Move down list to "pos" position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};

#endif //DATASTRUCTS_LINKEDLIST_H
