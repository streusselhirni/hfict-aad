#include <iostream>
#include "./ArrayUtil.h"

/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen Array enthä̈lt.
 * Das Resultat ist ein Array der gleichen Grösse. Jedes Element dieses Arrays beinhaltet die
 * Multiplikation aller Elemente (ausser sich selbst) des Input Arrays.
 *
 * Beispiel:
 * InputArray:{12, 4, 7, 3}
 * OutputArray:{4*7*3, 12*7*3, 12*4*3, 12*4*7} = {84, 252, 144, 336}
 */

int main() {
    std::cout << "\n\nAufgabe 2\n#####################" << std::endl;
    long values[] = {12, 4, 7, 3};
    long* newArray = ArrayUtil::multiplyArrayValues(values, 4);
    for (int i(0); i < 4; i++) {
        std::cout << "newArray[" << i << "]: " << newArray[i] << std::endl;
    }
    return 0;
}