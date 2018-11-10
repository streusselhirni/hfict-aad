#include <iostream>
#include <random>
#include <fstream>
#include "KlausurUtils.h"
#include "Tree.h"

int ran() {
    std::mt19937_64                    gen(clock());
    std::uniform_int_distribution<int> ran(0, 1000);
    return ran(gen);
}

int main() {
    Tree tree;

    // This tree has height 4
    std::vector<int> values = {8, 4, 10, 1, 6, 14, 7, 13};
//    std::vector<int> values;
//    KlausurUtils::loadFile("binarytree1.dat", values);

    for (int i = 0; i < values.size(); i++) {
        tree.insert(values[i]);
    }

    /*std::cout << "Pre-Order:" << std::endl;
    tree.printPreOrder();
    std::cout << std::endl;*/

    std::cout << "In-Order:" << std::endl;
    tree.printInOrder();
    std::cout << std::endl;

    /*std::cout << "Post-Order:" << std::endl;
    tree.printPostOrder();
    std::cout << std::endl;*/

    std::cout << "Height of tree: ";
    std::cout << tree.height();
    std::cout << std::endl;

    std::cout << "Number of nodes: ";
    std::cout << tree.count();
    std::cout << std::endl;

    int sum = 45;
    std::vector<int> path = tree.getPath(sum);
    tree.getPath(451);
    std::cout << "Pfad zur Summe " << sum << ":";
    for (int c: path) {
        std::cout << "->" << c;
    }
    std::cout << std::endl;
    return 0;
}