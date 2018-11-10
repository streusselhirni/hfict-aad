//
// Created by Nicolas Haenni on 23.10.18.
//

#include <iostream>
#include <vector>
#include "Result.h"
#include "ArrayUtil.h"

int main (int argc, char **argv) {
    nick::Result res;
    std::vector<int> input = {1, 2, 3, 4, 5, -1, -2, -3, -4, -5, 0};
    res = nick::ArrayUtil::analyzeArray(input);

    std::cout << "\nInput: ";
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(static_cast<unsigned long>(i));
        std::cout << (i == input.size() - 1 ? "\n" : ", ");
    }
    std::cout << std::endl;

    std::cout << "Positive Zahlen:\t" << res.nPositive << "%" << std::endl;
    std::cout << "Negative Zahlen:\t" << res.nNegative << "%" << std::endl;
    std::cout << "Null:\t\t\t\t" << res.nZero << "%" << std::endl;
    std::cout << std::endl;
    std::cout << "Total ist 100% +/- aufgrund Rundungsfehler." << std::endl;
    return 0;
}