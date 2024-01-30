cmake_minimum_required(VERSION 3.10)
project(SelectionSortProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(bubble_sort random_array.c bubble_sort.c)