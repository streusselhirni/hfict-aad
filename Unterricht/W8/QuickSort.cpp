//
// Created by Nicolas Haenni on 20.10.18.
//

#include "QuickSort.h"
#include <algorithm>

void QuickSort::sort(std::vector<int> &v) {
    // Abort condition
    if (v.size() <= 1) return;

    unsigned long pivotpos = rand() % v.size(); //NOLINT
    int tmp = v.at(pivotpos);
    v[pivotpos] = v.at(v.size()-1);
    v[v.size()-1] = tmp;
    int pivot = v.at(v.size()-1);

    std::vector<int> left;
    std::vector<int> right;

    // Divide & Conquer
    for (unsigned int i = 0; i < v.size() - 1; i++) {
        if (v.at(i) < pivot) {
            left.push_back(v.at(i));
        }
        else {
            right.push_back(v.at(i));
        }
    }

    this->sort(left);
    this->sort(right);

    // Merge
    for (unsigned int i = 0; i < left.size(); i++) {
        v[i] = left.at(i);
    }
    v[left.size()]      = pivot;
    for (unsigned int j = 0; j < right.size(); j++) {
        v[left.size() + j + 1] = right.at(j);
    }
}
