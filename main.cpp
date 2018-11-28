
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
//Testing ArrayBasedSimpleStat

    ArrayBasedSimpleStat<double> array1(100);
    vector<double> array2 = {88, 92, 88, 99, 102, 77, 80, 79, 103, 82, 102, 61, 101, 100};
    sort(array2.begin(), array2.end());
    for (auto i: array2) {
        array1.append(i);
        cout << i << endl;
    }

//    cout << array1.currPos() << endl;
//    cout << array1.getValue() << endl;
//    cout << "Mode: " << array1.mode() << endl;
//    cout << "Median: " << array1.median() << endl;
//    cout << "Mean: " << array1.mean() << endl;
//    cout << "SD: " << array1.SD() << endl;
    //Some codingkosndofsdkfjs
    cout << "rbsearch: " << array1.rbsearch(100, 0, array1.length()) << endl;
    cout << "ssearch: " << array1.ssearch(100) << endl;
//    cout << array2[1] << endl;
    cout << "ibsearch: " << array1.ibsearch(100) << endl;
}

