//
// Created by Nicolas Haenni on 09.11.18.
//
#include <iostream>
#include <set>
#include "../graph.h"

// Hilfsfuntion für depth-first search
void dfs(Graph* g, int current, std::set<int>& grassedNodes) {
    if (grassedNodes.find(current) != grassedNodes.end()) return;
    grassedNodes.insert(current);
    vector<int> neighbours = g->getNeighbours(current);
    for (int    n : neighbours) {
        dfs(g, n, grassedNodes);
    }
}

bool allNodeAreReachable(Graph* g, int start) {
    std::set<int> nodes;
    nodes.insert(start);
    dfs(g, 0, nodes);

    for (int i : nodes) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    return nodes.size() >= g->getNumberOfNodes();
}

int main() {
    Graph            g;
//    g.randomInit(10, 15, true);
    std::vector<int> w  = {2, 2, 2};
    std::vector<int> w2 = {2, 2};
    std::vector<int> n0 = {1, 2};
    std::vector<int> n1 = {0, 2};
    std::vector<int> n2 = {1, 0};
    std::vector<int> n3 = {1, 2, 0};
    g.addNode(n0, w2);
    g.addNode(n1, w2);
    g.addNode(n2, w2);
    g.addNode(n3, w);

    std::cout << "Gegebener Graph:" << std::endl;
    std::cout << g << std::endl;

    int start = 2;

    std::cout << "Können von " << start << " alle Nodes erreicht werden? "
              << (allNodeAreReachable(&g, 2) ? "Ja" : "Nein") << std::endl;

    return 0;
}