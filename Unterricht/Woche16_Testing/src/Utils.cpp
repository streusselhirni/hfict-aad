//
// Created by Nicolas Haenni on 2019-01-12.
//

#include "Utils.h"

int Utils::factorial(int a) {
    int res = 1;
    for (int i = a; i > 0; i--) {
        res *= i;
    }
    return res;
}
