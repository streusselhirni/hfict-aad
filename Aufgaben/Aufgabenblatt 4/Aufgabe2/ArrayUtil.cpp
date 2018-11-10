//
// Created by Nicolas Haenni on 23.10.18.
//

#include "ArrayUtil.h"

using namespace nick;

Result ArrayUtil::analyzeArray(std::vector<int> input) {
    int pos = 0,
        neg = 0,
        nul = 0,
        tot = 0;

    for (int c : input) {
        if (c < 0) neg++;
        else if (c > 0) pos++;
        else nul++;
        tot++;
    }

    return Result(neg*100/tot, pos*100/tot, nul*100/tot);
}
