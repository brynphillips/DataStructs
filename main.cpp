
#include <iostream>
#include "node.h"
#include "freeList.h"
#include "listInterface.h"
#include "linkedList.h"
#include "utilities.h"
#include "arrayBasedList.h"
#include "arrayBasedSimpleStat.h"
//#include <cassert>

int main(int argc, char *argv[]) {
    //Little fixes2
//Linked List Test
//    LList<int> test(0);
//    //return a.exec();
//    for (int i = 0; i < 10; i++)
//        test.insert(i); // adding 10 values. After this operation the curr (current pointer will be ath the tail)
//    for (int i = 0; i < 10; i++)
//        cout << "Removed " << 9 - i << " th value " << test.remove() << endl; // removing 10 values

//Array List test
//    AList<int> simple(100);
//    simple.insert(10);
//    cout << simple.length() << endl;
//    cout << simple.currPos() << endl;
//    cout << simple.getValue();

//Testing ArrayBasedSimpleStat

    ArrayBasedSimpleStat<int> simple(199);

}
