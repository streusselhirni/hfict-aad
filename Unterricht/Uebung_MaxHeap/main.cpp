#include <iostream>
#include <vector>

#include "HeapUtils.h"

int main() {
    std::vector<int> values = {105, 10, 99, 9, 2, 30, 91, 1, 3, 5, 1};

    if (HeapUtils::isMaxHeap(values)) {
        std::cout << "Is a maxHeap" << std::endl;
    }

    return 0;
}