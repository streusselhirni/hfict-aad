//
// Created by Nicolas Haenni on 2019-01-11.
//

#ifndef WOCHE_9_UND_10_CALCUTIL_H
#define WOCHE_9_UND_10_CALCUTIL_H

#include <string>
#include <vector>

class CalcUtil {
public:
    static void printSolutions();
private:
    static double convertToNumber(std::string word, const std::vector<char> values);
};


#endif //WOCHE_9_UND_10_CALCUTIL_H
