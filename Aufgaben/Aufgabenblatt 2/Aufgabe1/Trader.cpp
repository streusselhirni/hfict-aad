//
// Created by Nicolas Haenni on 12.09.18.
//

#include <iostream>
#include <climits>
#include "Trader.h"

int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) {

    int max(0), min(0), diff(-1), diffMin(INT_MIN);

    for (int i = 0; i < ARRAY_SIZE; i++) {

        for (int j = ARRAY_SIZE - 1; j > i; j--) {
            int tmp = values[j] - values[i];
            if (tmp > diff) diff = tmp;
            if (tmp < 0 && tmp > diffMin) diffMin = tmp;
        }

    }

    if (diff == -1) return diffMin;
    return diff;
}

// Lösung nach Yannick's Ansatz
int Trader::calculateMaxProfitLinear(const int *values, const int ARRAY_SIZE) {
    // In diesme Array wird immer die größte Zahl, die im values rechts von jeweiligen Index
    // noch auftaucht gespeichert. Vergleiche mit "Notiz.txt"
    auto biggestToRight = new int[ARRAY_SIZE]();
    auto i_biggestToRight = new int[ARRAY_SIZE]();

    // Durchlaufe die beiden Arrays von hinten und starte bei der vorletzten Stelle
    // (da die letzte Stelle keine darauf folgende Zahl mehr hat)
    for (int i = ARRAY_SIZE - 2; i >= 0; i--) {

        // Ist die Stelle, die wir einen Durchlauf vorher angesehen haben größer
        // als die größte Zahl,  die wir zuvor abgespeichert hatten?
        if (values[i + 1] >= biggestToRight[i + 1]) {
            // Wenn ja, speichere die Zahl values[i+1] als neue größte Zahl rechts vom aktuellen Index
            biggestToRight[i] = values[i + 1];
            i_biggestToRight[i] = i + 1;
        }
        else {
            // Wenn nein, speichere die vorherige größte Zahl als größte Zahl rechts vom aktuellen Index
            biggestToRight[i] = biggestToRight[i + 1];
            i_biggestToRight[i] = i_biggestToRight[i + 1];
        }
    }

    int curr(0), maxDiff(INT_MIN), i_buy(-1), i_sell(-1);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        curr = biggestToRight[i] - values[i];
        if (curr > maxDiff) {
            maxDiff = curr;
            i_buy = i;
            i_sell = i_biggestToRight[i];
        }
    }

    std::string timeToBuy = convertIndexToTime(i_buy);
    std::string timeToSell = convertIndexToTime(i_sell);

    std::cout << "\nKaufe um " << timeToBuy << " Uhr zum Preis von " << values[i_buy] << "." << std::endl;
    std::cout << "Verkaufe um " << timeToSell << " Uhr zum Preis von " << biggestToRight[i_sell] << "." << std::endl;
    std::cout << "Differenz: " << maxDiff << std::endl;

    return maxDiff;
}

std::string Trader::convertIndexToTime(int i) {
    if (i < 0) return "This should never happen";

    std::string smin, shour;

    int hour, min;
    hour = 9 + (i / 60);
    min = i % 60;

    if (min < 10) smin = "0" + std::to_string(min);
    else smin = std::to_string(min);
    if (hour < 10) shour = "0" + std::to_string(hour);
    else shour = std::to_string(hour);

    return shour + ':' + smin;
}

int Trader::calculateMaxProfitLinear(const int *values, const int ARRAY_SIZE, std::string &timeBuy,
                                     std::string &timeSell,
                                     int &vBuy, int &vSell) {
    // In diesme Array wird immer die größte Zahl, die im values rechts von jeweiligen Index
    // noch auftaucht gespeichert. Vergleiche mit "Notiz.txt"
    auto biggestToRight = new int[ARRAY_SIZE]();
    auto i_biggestToRight = new int[ARRAY_SIZE]();

    // Durchlaufe die beiden Arrays von hinten und starte bei der vorletzten Stelle
    // (da die letzte Stelle keine darauf folgende Zahl mehr hat)
    for (int i = ARRAY_SIZE - 2; i >= 0; i--) {

        // Ist die Stelle, die wir einen Durchlauf vorher angesehen haben größer
        // als die größte Zahl,  die wir zuvor abgespeichert hatten?
        if (values[i + 1] >= biggestToRight[i + 1]) {
            // Wenn ja, speichere die Zahl values[i+1] als neue größte Zahl rechts vom aktuellen Index
            biggestToRight[i] = values[i + 1];
            i_biggestToRight[i] = i + 1;
        }
        else {
            // Wenn nein, speichere die vorherige größte Zahl als größte Zahl rechts vom aktuellen Index
            biggestToRight[i] = biggestToRight[i + 1];
            i_biggestToRight[i] = i_biggestToRight[i + 1];
        }
    }

    int curr(0), maxDiff(INT_MIN), i_buy(-1), i_sell(-1);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        curr = biggestToRight[i] - values[i];
        if (curr > maxDiff) {
            maxDiff = curr;
            i_buy = i;
            i_sell = i_biggestToRight[i];
        }
    }
    
    vBuy = values[i_buy];
    vSell = biggestToRight[i_sell];
    timeBuy = convertIndexToTime(i_buy);
    timeSell = convertIndexToTime(i_sell);
    return maxDiff;
}
