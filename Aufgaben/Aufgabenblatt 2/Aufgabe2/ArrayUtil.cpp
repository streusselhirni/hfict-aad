//
// Created by Nicolas Haenni on 12.09.18.
//

#include "ArrayUtil.h"
#include <iostream>

int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE) {
    int prodPos(1);
    int prodNeg(1);

    // Sort array
    sort(values, ARRAY_SIZE);

    // Sortiertes Array ausgeben
    std::cout << "Sortiertes Array: \t\t";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << values[i] << "\t\t";
    }
    std::cout << std::endl;

    // Produkt der drei größten Zahlen
    for (int i = ARRAY_SIZE - 1; i > ARRAY_SIZE - 4; i--) {
        prodPos *= values[i];
    }

    // Produkt der zwei kleinsten Zahlen
    for (int i = 0; i < 2; i++) {
        prodNeg *= values[i];
    }

    // Produkt der zwei kleinsten und der größten Zahl
    prodNeg *= values[ARRAY_SIZE - 1];

    // Checke, welcher Wert zuruckgegeben wird
    if (prodPos > prodNeg) {
        return prodPos;
    }
    return prodNeg;
}

void ArrayUtil::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ArrayUtil::sort(int *values, const int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        // Sortiere Stelle i
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            // Gehe durch Array und schiebe alles, was größer ist Ab Stelle i nach hinten
            if (values[j] > values[j + 1]) {
                swap(&values[j], &values[j + 1]);
            }
        }
    }
}
