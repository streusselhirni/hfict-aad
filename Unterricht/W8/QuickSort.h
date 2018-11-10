//
// Created by Nicolas Haenni on 20.10.18.
//

#ifndef W7_QUICKSORT_H
#define W7_QUICKSORT_H


#include "Sort.h"

class QuickSort : public Sort {
public:
    void sort(std::vector<int> & v) override;
};


#endif //W7_QUICKSORT_H
