#include <iostream>
#include <random>
#include "ProcessList.h"
#include "MaxHeap.h"

int main() {
    const int INITIAL_SIZE                 = 1000;
    const int N_OPERATIONS                 = 100000;

    std::default_random_engine         generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    auto                               ran = std::bind(distribution, generator);

    MaxHeap  mh;
    for (int i                             = 0; i < 10; i++) {
        int v = ran();
        mh.insert(v);
        std::cout << "Insert: " << v << std::endl;
        char ch;
        std::cin >> ch;
        mh.print();
    }

    return 0;
}