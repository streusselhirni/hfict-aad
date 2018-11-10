//
// Created by Nicolas Haenni on 23.10.18.
//

#ifndef WOCHE_7_UND_8_RESULT_H
#define WOCHE_7_UND_8_RESULT_H


namespace nick {
    class Result {
    public:
        int nPositive;
        int nNegative;
        int nZero;
        Result();
        Result(int pos, int neg, int nul);
        Result(double pos, double neg, double nul);
    };
}

#endif //WOCHE_7_UND_8_RESULT_H
