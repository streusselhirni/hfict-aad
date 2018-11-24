//
// Created by Nicolas Haenni on 13.11.18.
//

#include <iostream>
#include "TreeUtil.h"

/**
 * This is a greedy algorithm
 */
void TreeUtil::printMaximumPathGreedy(std::vector<int> values) {
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
        std::cout << "-->" << c;
    }
    std::cout << std::endl;
}

void TreeUtil::printMaximumPath(std::vector<int> values) {
    unsigned long    idx     = values.size() - 1;
    std::vector<int> bestPath;
    int              bestSum = 0;

    while (idx > 0) {
        // Wir wollen nur Leaf-Nodes
        if (idx * 2 + 1 >= values.size() && idx * 2 + 2 >= values.size()) {
            unsigned long    tmpIdx = idx;
            std::vector<int> tmpPath;
            int              tmpSum = 0;
            while (tmpIdx > 0) {
                tmpPath.push_back(values.at(tmpIdx));
                tmpSum += values.at(tmpIdx);

                int leftOrRight = (idx % 2 == 1 ? 1 : 2);

                tmpIdx = (tmpIdx - leftOrRight) / 2;
            }
            tmpPath.push_back(values.at(0));
            tmpSum += values.at(0);

            if (tmpSum > bestSum) {
                bestSum = tmpSum;
                std::reverse(tmpPath.begin(), tmpPath.end());
                bestPath = tmpPath;
            }
        }
        else {
            break;
        }
        idx--;
    }

    std::cout << "Beste Summe: " << bestSum << std::endl;
    std::cout << "Pfad dort hin: ";
    for (int const& v : bestPath) {
        std::cout << "-->" << v;
    }
    std::cout << std::endl;
}
