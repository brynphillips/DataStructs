
#include <iostream>
#include "node.h"
#include "freeList.h"
#include "listInterface.h"
#include "linkedList.h"
#include "utilities.h"
//#include <cassert>

    int main(int argc, char *argv[]) {

        LList<int> test(0);
        //return a.exec();
        for (int i = 0; i < 10; i++)
            test.insert(i); // adding 10 values. After this operation the curr (current pointer will be ath the tail)
        for (int i = 0; i < 10; i++)
            std::cout << "Removed " << 9 - i << " th value " << test.remove() << endl; // removing 10 values
    }
