
SET(BOOST_PATH "/Users/vladdr/bin/common/boost_1_81_0")
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/Users/vladdr/bin/common/boost_1_81_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/Users/vladdr/bin/common/boost_1_81_0/lib")

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable (Boost_Tests_run lru_tests.cpp)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})