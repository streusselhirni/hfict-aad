//
// Created by Nicolas Haenni on 12.09.18.
//

#ifndef AUFGABE1_TRADER_H
#define AUFGABE1_TRADER_H

#include <string>

class Trader {
private:
    static std::string convertIndexToTime(int i);
public:
    static int calculateMaxProfit(const int *values, const int ARRAY_SIZE);
    static int calculateMaxProfitLinear(const int *values, const int ARRAY_SIZE);
    static int calculateMaxProfitLinear(const int *values,
                                        const int ARRAY_SIZE,
                                        std::string &timeBuy,
                                        std::string &timeSell,
                                        int &vBuy,
                                        int &vSell);
};


#endif //AUFGABE1_TRADER_H
