//
// Created by Nicolas Haenni on 15.09.18.
//

#ifndef WOCHE_5_UND_6_COINCOMBINATION_H
#define WOCHE_5_UND_6_COINCOMBINATION_H


class CoinCombination {
public:
    static int number(
            double value,
            const double *coins,
            const int ARRAY_SIZE
            );
    static void printCoinCombination(
            double value, // Betrag
            const double *coins, // Pointer auf Münzarray
            const int ARRAY_SIZE); // Größe des Münzarrays
};


#endif //WOCHE_5_UND_6_COINCOMBINATION_H
