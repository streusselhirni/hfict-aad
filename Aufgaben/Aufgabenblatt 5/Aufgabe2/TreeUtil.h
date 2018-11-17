//
// Created by Nicolas Haenni on 13.11.18.
//

#ifndef AUFGABENBLATT_5_TREEUTIL_H
#define AUFGABENBLATT_5_TREEUTIL_H

#include <vector>

class TreeUtil {
public:
    static bool isBinarySearchTree(std::vector<int> values, int idx, int min, int max);
};


#endif //AUFGABENBLATT_5_TREEUTIL_H
