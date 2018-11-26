
#include <iostream>
#include <algorithm>
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

    ArrayBasedSimpleStat<double> array1(100);
    vector<double> array2 = {88, 92, 88, 99, 102, 77, 80, 79, 103, 82, 102, 61, 101, 100, 11};
    sort(array2.begin(), array2.end());
    for (auto i: array2) {
        array1.append(i);
        cout << i << endl;
    }

//    cout << array1.currPos() << endl;
//    cout << array1.getValue() << endl;
//    cout << array1.mode();
//    cout << array1.mean();
//    cout << array1.SD();
//    cout << array1.ssearch(88);
    cout << array2[1] << endl;
    cout << array1.ibsearch(100);
}

