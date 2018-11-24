//
// Created by Nicolas Haenni on 13.11.18.
//
#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
#include "TreeUtil.h"

int main (int argc, char **argv) {
//    std::vector<int> values = {20, 12, 34, 9, 19, 29};                               // is search tree
//    std::vector<int> values = {100, 50, 150, 25, 75, 125, 175};                      // is search tree
//    std::vector<int> values = {10, 8, 12, 4, 9, 11, 16};                             // is search tree
//    std::vector<int> values = {10, 8, 12, 4, 15, 9, 16};                             // is no search tree
//    std::vector<int> values = {10, 8, 12, 4, 15, 9, 16, 2, 5, 4, 18, 8, 14, 10, 8};  // is no search tree
//    std::vector<int> values = {10, 5, 15, 3, 7, 5, 18};                              // is no search tree
//    std::vector<int> values = {10, 5, 15, 3, 7, 12, 18};                             // is search tree
    std::vector<int> values = {10, 8, 12, 9};

    std::cout << "Werte in Array:" << std::endl;
    for (const int &c : values) {
        std::cout << std::setw(4) << c << (c == *(values.end() - 1) ? "" : ", ");
    }
    std::cout << std::endl;

    std::cout << "Binärer Suchbaum: ";
    std::cout << (TreeUtil::isBinarySearchTree(values, 0, INT_MIN, INT_MAX) ? "Ja" : "Nein") << std::endl;


    return 0;
}