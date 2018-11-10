//
// Created by Nicolas Haenni on 23.10.18.
//

#include "Result.h"

using namespace nick;

Result::Result() : nPositive(0), nNegative(0), nZero(0) {}

Result::Result(int pos, int neg, int nul) : nPositive(pos), nNegative(neg), nZero(nul) {}

Result::Result(double pos, double neg, double nul) : nPositive(static_cast<int>(pos)),
                                                     nNegative(static_cast<int>(neg)),
                                                     nZero(static_cast<int>(nul)) {}
