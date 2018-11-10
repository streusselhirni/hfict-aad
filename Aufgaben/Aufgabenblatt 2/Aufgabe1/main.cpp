#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
#include "Trader.h"

int *generateShares(const int size, int startPrice) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(1, 10); // guaranteed unbiased

    auto result = new int(size);

    result[0] = startPrice;
    for (int i = 1; i < size; i++) {
        int random = uni(rng);
        if (random % 2 == 0) {
            result[i] = result[i - 1] + random;
        }
        else {
            if (result[i - 1] - random < 0) result[i] = 1;
            else result[i] = result[i - 1] - random;
        }
    }
    return result;
}

int main() {
    clock_t start, stop;
    const int size = 510; // 510 Minuten von 09:00 bis 17:30
    int *shares = generateShares(size, 10); // Aktienwerte generieren

//    int shares[] = {50, 49, 48, 47, 46, 45, 44, 43, 42, 41};
//    int shares[] = {41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
//    int shares[] = {4, 24, 1, 10};

    std::cout << "Aktienwerte" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(6) << shares[i];

        if ((i + 1) % 30 == 0) std::cout << std::endl;
    }
    std::cout << "\n\n" << std::endl;

    start = clock();
    std::cout << "Differenz 1: " << Trader::calculateMaxProfit(shares, size) << std::endl;
    stop = clock();
    std::cout << "(" << (double)(stop-start)/CLOCKS_PER_SEC << "s)" << std::endl;


    std::string timeBuy, timeSell;
    int vBuy = 0, vSell = 0;

    start = clock();
    std::cout << "Um " <<
              Trader::calculateMaxProfitLinear(shares, size, timeBuy, timeSell, vBuy, vSell) <<
              " Gewinn zu machen, musst du um " << timeBuy << " Uhr zum Preis von " << vBuy <<
              " kaufen und um " << timeSell << " Uhr zum Preis von " << vSell << " verkaufen." << std::endl;
    stop = clock();
    std::cout << "(" << (double)(stop-start)/CLOCKS_PER_SEC << "s)" << std::endl;
    return 0;
}