#include <iostream>
#include <vector>
#include <random>
#include "InsertionSort.h"

std::vector<int> randomValues(unsigned int n) {
    std::vector<int> result(n);
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> rand(0, 1000);
    for (int i = 0; i < n; i++) {
        result.at(static_cast<unsigned int>(i)) = rand(gen);
    }
    return result;
}

int main(int argc, char **argv) {

    std::vector<int> v = randomValues(10);

    InsertionSort isort;

    isort.sort(v);

    for( auto i : v) std::cout << i << std::endl;

    return 0;
}