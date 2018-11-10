#include <iostream>
#include <string>
#include "StringUtil.h"

int main() {
    std::string input = "poiuypoiuyge";
    char lonely = StringUtil::getLonelyElement(input);

    std::cout << "Input: " << input << std::endl;
    std::cout << "Folgender Buchstaben kommt nur einmal vor: " << lonely << std::endl;
    return 0;
}