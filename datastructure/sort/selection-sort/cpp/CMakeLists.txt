cmake_minimum_required(VERSION 3.10)
project(SelectionSortCPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(selection_sort selection_sort.cpp random_array.cpp)

