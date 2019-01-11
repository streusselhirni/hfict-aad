//
// Created by Nicolas Haenni on 2019-01-11.
//

#include <iostream>
#include "Graph.h"

int main(int argc, char** argv) {
    // Create graph
    Graph myGraph;
    myGraph.addNode({1, 2, 3}, {1, 1, 1});  // 0
    myGraph.addNode({0, 4}, {1, 1});        // 1
    myGraph.addNode({0}, {1});              // 2
    myGraph.addNode({0, 5, 6}, {1, 1, 1});  // 3
    myGraph.addNode({1}, {1});              // 4
    myGraph.addNode({3, 7}, {1, 1});        // 5
    myGraph.addNode({3}, {1});              // 6
    myGraph.addNode({5}, {1});              // 7

    std::cout << std::endl;
    std::cout << myGraph << std::endl;
    std::cout << "Is tree: " << (myGraph.checkGraphIsTree() ? "TRUE" : "FALSE") << std::endl;


    return 0;
}