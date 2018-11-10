//
// Created by Nicolas Haenni on 12.09.18.
//

#ifndef AUFGABE2_ARRAYUTIL_H
#define AUFGABE2_ARRAYUTIL_H


class ArrayUtil {
private:
    static void swap(int *x, int *y);
    static void sort(int *values, const int ARRAY_SIZE);
public:
    static int highestProduct(int *values, const int ARRAY_SIZE);
};


#endif //AUFGABE2_ARRAYUTIL_H
