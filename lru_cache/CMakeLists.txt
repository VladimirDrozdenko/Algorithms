cmake_minimum_required(VERSION 3.24)

project(lru_cache)

set(CMAKE_CXX_STANDARD 17)

add_executable (lru main.cpp LRU.h List.h)

add_subdirectory(Boost_tests)
