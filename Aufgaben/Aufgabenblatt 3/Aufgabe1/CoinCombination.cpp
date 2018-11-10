//
// Created by Nicolas Haenni on 15.09.18.
//

#include <iostream>
#include <iomanip>  // setw()
#include <vector>
#include "CoinCombination.h"

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE) {
    // Variablen deklarieren
    auto             lvalue = static_cast<long>(value * 100);   // Value als long
    std::vector<int> lcoins(static_cast<unsigned int>(ARRAY_SIZE));// Coins-Array als long-Werte
    std::vector<int> noOfCoins(static_cast<unsigned int>(ARRAY_SIZE));   // Zählarray

    // Betrag und Münzen ausgeben
    std::cout << "Betrag: " << value << std::endl;
    std::cout << "Münzen: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << coins[i] << (i < ARRAY_SIZE - 1 ? ", " : "");
    }
    std::cout << "\n" << std::endl;

    // Werte von coins-Array ind lcoins kopieren und zu long konvertieren
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        lcoins.at(static_cast<unsigned long>(i)) = static_cast<int>(coins[i] * 100);
    }

    // Jede Münze prüfen
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        noOfCoins[i] = static_cast<int>(lvalue / lcoins[i]);

        lvalue -= (noOfCoins[i] * lcoins[i]);
    }

    // Ausgabe der Münzen
    std::cout << "Verfügbare Münzen:\t";
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        std::cout << std::setw(8) << coins[i];
    }
    std::cout << std::endl;
    std::cout << "Benötigte Münzen:\t";
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        std::cout << std::setw(8) << noOfCoins[i];
    }
    std::cout << std::endl;
}