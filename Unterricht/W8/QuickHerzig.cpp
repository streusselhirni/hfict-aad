//
// Created by Nicolas Haenni on 20.10.18.
//

#include "QuickHerzig.h"

void QuickHerzig::sort(std::vector<int> &v) {
    // abort
    if (v.size() <= 1) return;

    //int pivot = v.at(v.size()-1);
    int pivotpos = rand() % v.size();
    int tmp      = v.at(pivotpos);
    v[pivotpos]     = v.at(v.size() - 1);
    v[v.size() - 1] = tmp;
    int pivot          = v.at(v.size() - 1);

    // divide & conquer
    std::vector<int> left;
    std::vector<int> right;
    for (int         i = 0; i < v.size() - 1; i++) {
        if (v.at(i) < pivot) {
            left.push_back(v.at(i));
        }
        else {
            right.push_back(v.at(i));
        }
    }

    sort(left);
    sort(right);

    // merge
    for (int i     = 0; i < left.size(); i++) {
        v[i] = left.at(i);
    }
    v[left.size()] = pivot;
    for (int i = 0; i < right.size(); i++) {
        v[left.size() + i + 1] = right.at(i);
    }
}