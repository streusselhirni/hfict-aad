#include <iostream>
#include "CoinCombination.h"

void wait() {
    // Wait with finish in case we execute all Aufgaben after each other
    std::cout << "\n\nPress Enter to Continue";
    std::cin.ignore();
}

int main() {
    std::cout << "#####################\n     Aufgabe 1\n#####################\n" << std::endl;
    double betrag = 13.85;
    const int ARRAY_SIZE = 7;
    double coins[ARRAY_SIZE] = { 0.05, 0.1, 0.2, 0.5, 1, 2 ,5 };

    CoinCombination::printCoinCombination(betrag, coins, ARRAY_SIZE);

    return 0;
}
