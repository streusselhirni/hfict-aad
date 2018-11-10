#include <iostream>
#include "StringUtil.h"

/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen String enthä̈lt.
 * Das Resultat ist ein Boolean. true falls alle Buchstaben unique sind (alle Buchstaben kommen nur einmal vor),
 * sonst false.
 */

int main() {
    std::string s = "abc4def$%^%ghij';klm\'no\"pqrstuvwxyz1234567890-][';/...,";

    std::cout << "String: " << s << std::endl;

    std::cout << "Alle Buchstaben einzigartig? " << (StringUtil::checkUniqueness(s) ? "Ja" : "Nein") << std::endl;
    return 0;
}