
#define BOOST_TEST_MODULE Boost_tests
#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;

#include "../LRU.h"

BOOST_AUTO_TEST_CASE( test1 )
{
    LRU<int, int> lru(2);
    lru.put(1, 1);
    lru.put(2, 2);

    const int* p = lru.get(1);
    BOOST_CHECK_MESSAGE(p && *p == 1, "Test1");

    lru.put(3, 3);
    p = lru.get(2);
    BOOST_CHECK_MESSAGE(p == nullptr, "Test2");

    lru.put(4, 4);
    p = lru.get(1);
    BOOST_CHECK_MESSAGE(p == nullptr, "Test2");

    p = lru.get(3);
    BOOST_CHECK(p && *p == 3);

    p = lru.get(4);
    BOOST_CHECK(p && *p == 4);
}

BOOST_AUTO_TEST_CASE( test2 )
{
    LRU<int, int> lru(2);
    lru.put(2, 1);
    lru.put(1, 1);
    lru.put(2, 3);
    lru.put(4, 1);

    const int* p = lru.get(1);
    BOOST_CHECK(p == nullptr);

    p = lru.get(2);
    BOOST_CHECK(p && *p == 3);
}