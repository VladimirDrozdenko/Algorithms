//
// Created by Drozdenko, Vladimir on 12/12/22.
//

#include <iostream>
#include "LRU.h"

using namespace std;

void printVal(const string *pVal) {
    if (pVal != nullptr) {
        cout << (*pVal) << endl;
    } else {
        cout << "null" << endl;
    }
}

int main() {

    LRU<int, string> lru(2);
    lru.put(1, "1.0");
    lru.put(2, "2.0");
    lru.put(1, "1.1");
    lru.put(3, "3.0");
    lru.put(4, "4.0");
    lru.put(5, "5.0");

    printVal(lru.get(1));
    printVal(lru.get(2));
    printVal(lru.get(3));

    return 0;
}


