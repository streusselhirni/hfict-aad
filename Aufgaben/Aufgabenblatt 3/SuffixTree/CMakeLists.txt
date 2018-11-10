cmake_minimum_required(VERSION 3.12)
project(SuffixTree)
set(CMAKE_CXX_STANDARD 17)

add_executable(SuffixTree main.cpp SuffixTreeNode.h SuffixBaum.h SuffixBaum.cpp)