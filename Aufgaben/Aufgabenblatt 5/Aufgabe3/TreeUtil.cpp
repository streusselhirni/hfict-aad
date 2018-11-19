//
// Created by Nicolas Haenni on 13.11.18.
//

#include <iostream>
#include "TreeUtil.h"

/**
 * This is a greedy algorithm
 */
void TreeUtil::printMaximumPath(std::vector<int> values) {
    unsigned int     idx = 0;
    std::vector<int> res;

    while (idx < values.size()) {
        if (idx == 0) {
            res.push_back(values.at(idx));
        }

        unsigned int left  = idx * 2 + 1;
        unsigned int right = idx * 2 + 2;

        if (left < values.size() && values.at(left) > values.at(right)) {
            res.push_back(values.at(left));
            idx = left;
        }
        else if (right < values.size() && values.at(right) > values.at(left)) {
            res.push_back(values.at(right));
            idx = right;
        }
        else {
            idx++;
        }
    }

    std::cout << "Der Pfad mit der größten Summe ist: ";
    for (const int& c: res) {
        std::cout << "-->" << c ;
    }
    std::cout << std::endl;
}
