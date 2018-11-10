//
// Created by Nicolas Haenni on 20.10.18.
//

#ifndef W7_MERGESORT_H
#define W7_MERGESORT_H


#include "Sort.h"

class MergeSort : public Sort {
public:
    void sort(std::vector<int> &v) override;
};

#endif //W7_MERGESORT_H
