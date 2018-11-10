//
// Created by Nicolas Haenni on 20.10.18.
//

#include "MergeSort.h"

void MergeSort::sort(std::vector<int> &v) {
    // Abort Condition
    if (v.size() <= 1) return;

    // Bei zwei Elementen nur noch sortieren
    if (v.size() == 2) {
        if (v.at(0) > v.at(1)) {
            std::swap(v.at(0), v.at(1));
        }
        return;
    }

    std::vector<int> left;
    std::vector<int> right;

    // Auf zwei Hälften sortieren (bei ungeraden Elementen ist die linke Hälfte größer)
    for (unsigned int i = 0; i < v.size(); i++) {
        if (i < v.size()/2) {
            left.push_back(v.at(i));
        }
        else {
            right.push_back(v.at(i));
        }
    }

    this->sort(left);
    this->sort(right);

    unsigned long iL = 0;
    unsigned long iR = 0;

    for (unsigned long i = 0; i < v.size(); i++) { //NOLINT
        if (iL >= left.size()) {
            v.at(i) = right.at(iR++);
            continue;
        }

        if (iR >= right.size()) {
            v.at(i) = left.at(iL++);
            continue;
        }

        if (left.at(iL) <= right.at(iR)) {
            v.at(i) = left.at(iL++);
        }
        else {
            v.at(i) = right.at(iR++);
        }
    }
}
