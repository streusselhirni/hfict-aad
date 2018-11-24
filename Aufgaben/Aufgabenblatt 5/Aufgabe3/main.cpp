//
// Created by Nicolas Haenni on 13.11.18.
//
#include <iostream>
#include <vector>
#include "TreeUtil.h"

int main (int argc, char **argv) {
    // Values from excercise
//    std::vector<int> values = {40, 100, 200, 20, 40, 70, 80, 50, 10};
    // Values to demonstrate that this is a greedy algorithm
    std::vector<int> values = {40, 100, 200, 20, 40, 70, 80, 500, 10};

    TreeUtil::printMaximumPathGreedy(values);

    return 0;
}