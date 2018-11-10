#include <iostream>
#include <string>
#include "StringUtil.h"

int main() {
    std::cout << "#####################\n     Aufgabe 2\n#####################\n" << std::endl;

//    std::string input = "1234567890987654321";
    std::string input = "Ich mag Züge";
//    std::string input = "Ein Neger mit Gazelle zagt im Regen nie";

    std::cout << "\"" << input << "\" ";
    std::cout << (StringUtil::isPalindrome(input) ? "is ein Palindrom." : "ist kein Palindrom") <<std::endl ;

    return 0;
}
