#include <iostream>
#include "LRU.h"

using namespace std;


static void Assert(const char* const msg, bool expr) {
    cout << "Test \"" << msg << "\"";
    if (expr) {
        cout << " SUCCESS" << endl;
    } else {
        cout << " FAILED" << endl;
    }
}

static void Test1() {
    LRU<int, int> lru(2);
    lru.put(1, 1);
    lru.put(2, 2);

    const int* p = lru.get(1);
    Assert("Test1, 1", p && *p == 1);

    lru.put(3, 3);
    p = lru.get(2);
    Assert("Test1, 2", p == nullptr);

    lru.put(4, 4);
    p = lru.get(1);
    Assert("Test1, 3", p == nullptr);

    p = lru.get(3);
    Assert("Test1, 4", p && *p == 3);

    p = lru.get(4);
    Assert("Test1, 5", p && *p == 4);
}

static void Test2() {
    LRU<int, int> lru(2);
    lru.put(2, 1);
    lru.put(1, 1);
    lru.put(2, 3);
    lru.put(4, 1);

    const int* p = lru.get(1);
    Assert("Test2, 1", p == nullptr);

    p = lru.get(2);
    Assert("Test2, 2", p && *p == 3);
}

int main() {

    Test1();

    Test2();

    return 0;
}


