//
// Created by Nicolas Haenni on 2019-01-11.
//
#include "CalcUtil.h"
#include <iostream>
#include <cmath>
#include <algorithm>

void CalcUtil::printSolutions() {
    std::vector<std::string> wordEquation;  // 0-(n-2) = summand; n-1 = sum
    wordEquation.push_back("MATHE");
    wordEquation.push_back("IST");
    wordEquation.push_back("MEIN");
    std::string wordSum = "LEBEN";

    for (const auto& word : wordEquation) std::cout << word << " + ";
    std::cout << "\b\b"
              << "= " << wordSum << std::endl;

    std::vector<char> letters{'A', 'B', 'E', 'H', 'I', 'L', 'M', 'N', 'S', 'T'};

    do {
        std::vector<int> numberEquation;
        int              left = 0;

        for (const auto& word : wordEquation) {
            int number = convertToNumber(word, letters);
            left += number;
            numberEquation.push_back(number);
        }

        int right = convertToNumber(wordSum, letters);

        if (left == right) {
            /* for (const auto& letter : letters) cout << letter << "  ";
            cout << endl; */
            for (const auto& number : numberEquation) std::cout << number << " + ";
            std::cout << "\b\b"
                      << "= " << right << std::endl;
        }

    } while (next_permutation(letters.begin(), letters.end()));
}

double CalcUtil::convertToNumber(std::string word, const std::vector<char> values) {
    double      number = 0;
    for (int i      = 0; i < word.size(); i++) {
        double significance = round(pow(10, word.size() - i - 1));
        long   value        = find(values.begin(), values.end(), word.at(i)) - values.begin();

        /* std::cout << "convertToNumber: i = " << i << ", value = " << *find(values.begin(), values.end(), word.at(i))
        << " - " << *values.begin() << " = " << value << std::endl; */

        number += value * significance;
    }

    return number;
}