#include <iostream>
#include <random>
#include "ArrayUtil.h"

int* generateArray(int size, int min, int max) {
    auto result = new int[size];
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    for (int  i = 0; i < size; i++) {
        result[i] = uni(rng);
    }
    return result;
}

int main() {
    const int size = 15;
    int *arr = generateArray(size, -10, 10);
//    int arr[size] = {-100, -99, -98, 1, 2, 3};
    std::cout << "Generiertes Array:\t\t";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t\t";
    }
    std::cout << std::endl;

    int result = ArrayUtil::highestProduct(arr, size);

    std::cout << "Größtes Produkt aus drei Zahlen: " << result << std::endl;

    return 0;
}