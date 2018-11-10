#include <iostream>
#include <random>
#include <ctime>
#include "Tree.h"

int ran() {
    std::mt19937_64 gen(clock());
    std::uniform_int_distribution<int> ran(0, 1000);
    return ran(gen);
}

int main() {
    Tree tree;

    int values[] = {8, 4, 10, 1, 6, 14, 7, 13};

    for (int i = 0; i < 8; i++) {
        tree.insert(values[i]);
    }

    tree.printInOrder();

    return 0;
}