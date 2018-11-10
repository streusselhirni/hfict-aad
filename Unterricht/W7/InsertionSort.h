//
// Created by Nicolas Haenni on 29.09.18.
//

#ifndef W7_INSERTIONSORT_H
#define W7_INSERTIONSORT_H

#include "Sort.h"

class InsertionSort : public Sort {
public:
    virtual void sort(std::vector<int> & v);
};


#endif //W7_INSERTIONSORT_H
