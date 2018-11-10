#include <iostream>
#include <vector>
#include <random>
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "QuickHerzig.h"

std::vector<int> randomValues(unsigned int n) {
    std::vector<int>                   result(n);
    std::mt19937                       gen(std::random_device{}());
    std::uniform_int_distribution<int> rand(0, RAND_MAX);
    for (int                           i = 0; i < n; i++) {
        result.at(static_cast<unsigned int>(i)) = rand(gen);
//        result.at(i) = i;
    }
    return result;
}

int main(int argc, char **argv) {
    // TODO Find recursion depth
    // TODO Find out how much time is used for splitting and merging (Quick/Merge Sort)
    // TODO Optimize code, eg. do not copy data all the time

    std::vector<int> v = randomValues(5000000);

    MergeSort sorter;
    clock_t   start, stop;

    start = clock();
    sorter.sort(v);
    stop = clock();

//    for (auto i : v) std::cout << i << std::endl;
    std::cout << "Zeit: " << (double)(stop - start)/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << RAND_MAX << std::endl;
    
    return 0;
}