//
// Created by Nicolas Haenni on 29.09.18.
//

#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int> &v) {
    for (unsigned int i = 1; i < v.size(); i++) {

        for (unsigned int j = 0; j < i; j++) {
            if (v.at(i) < v.at(j)) {
                int tmp = v.at(j);
                v.at(j) = v.at(i);
                v.at(i) = tmp;
            }
        }
    }
}
