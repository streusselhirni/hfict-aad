//
// Created by Nicolas Haenni on 23.10.18.
//

#include "StringUtil.h"
#include <iostream>
#include <vector>
#include <map>

char StringUtil::getLonelyElement(std::string input) {
    std::vector<int>  countArr(128);

    for (char c : input) {
        countArr.at(static_cast<unsigned long>(c))++;
    }

    for (unsigned long i = 0; i < countArr.size(); i++) {
        if (countArr.at(i) == 1) {
            return static_cast<char>(i);
        }
    }

    return 0;
}
