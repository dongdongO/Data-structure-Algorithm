cmake_minimum_required(VERSION 3.10)
project(SelectionSortProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(insert_sort random_array.c insert_sort.c)

