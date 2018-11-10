cmake_minimum_required(VERSION 3.12)
project(W7)

set(CMAKE_CXX_STANDARD 17)

add_executable(W7 main.cpp Sort.h InsertionSort.cpp InsertionSort.h QuickSort.cpp QuickSort.h MergeSort.cpp MergeSort.h QuickHerzig.cpp QuickHerzig.h)