//
// Created by Nicolas Haenni on 23.09.18.
//

#include <iostream>
#include "StringUtil.h"

bool StringUtil::isPalindrome(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());

    if (input.size() <= 1) return true;

    if (toupper(input.at(0)) == toupper(input.at(input.size() - 1))) {
        std::string substring = input.substr(1, input.size()  - 2);
        return StringUtil::isPalindrome(substring);
    }

    return false;
}
