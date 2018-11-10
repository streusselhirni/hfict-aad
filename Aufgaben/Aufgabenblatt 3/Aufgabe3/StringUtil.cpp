//
// Created by Nicolas Haenni on 23.09.18.
//

#include "StringUtil.h"
#include <string>       // for strings
#include <vector>       // for vectors
#include <algorithm>    // for std::transform
#include <iostream>

std::string StringUtil::lcs(std::string input1, std::string input2) {
    int                            m            = static_cast<int>(input1.size());
    int                            n            = static_cast<int>(input2.size());
    int                            biggest      = 0;
    int                            startBiggest = 0;
    // Erstelle zweidimensionalen Vector (siehe Excel-Tabelle in Repository)
    std::vector<std::vector<int> > matrix(m + 1, std::vector<int>(n));

    // Konvertiere Strings zu lowercase
    std::transform(input1.begin(), input1.end(), input1.begin(), ::tolower);
    std::transform(input2.begin(), input2.end(), input2.begin(), ::tolower);

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            }

            else if (input1.at(i - 1) == input2.at(j - 1)) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                if (matrix[i][j] > biggest) {
                    biggest = matrix[i][j];
                    startBiggest = i - biggest;
                }
            }

            else {
                matrix[i][j] = 0;
            }
        }
    }
    
    std::cout << "String 1:\t" << input1 << std::endl;
    std::cout << "Länge String 1: " << input1.length() << std::endl;
    std::cout << "String 2:\t" << input2 << std::endl;
    std::cout << "Länge String 2: " << input2.length() << std::endl;
    std::cout << std::endl;
    std::cout << "Substring:\t\"" << input1.substr(startBiggest, biggest) << "\"" << std::endl;
    std::cout << "(Länge: " << biggest << ")" << std::endl;

    return std::string();
}