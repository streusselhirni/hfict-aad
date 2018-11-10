//
// Created by Nicolas Haenni on 24.08.18.
//
#include <iostream>
#include "ArrayUtil.h"

long *ArrayUtil::multiplyArrayValues(const long *values, const int ARRAY_SIZE) {
    long *result = new long[ARRAY_SIZE];

    // Loop through result array
    for (int i(0); i < ARRAY_SIZE; i++) {
        result[i] = 1; // Start multiplying with value 1
        // Loop through source array (values)
        for (int j(0); j < ARRAY_SIZE ; j++) {
            // multiply current result value with next number from values, when not itself
            if (i != j) result[i] *= values[j];
        }
    }
    return result;
}
