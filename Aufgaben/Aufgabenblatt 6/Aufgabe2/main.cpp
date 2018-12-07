//
// Created by Nicolas Haenni on 09.11.18.
//
#include <iostream>
#include <climits>
#include <map>
#include <iomanip>
#include "../graph.h"

int minimumHops(Graph *g, int start, int end) {
    // Falls start und end gleich sind
    if (start == end) return 0;

    vector<int> visited;  // Nodes bei denen wir schon waren
    vector<int> hops;     // Anzahl hops zur jeweiligen Node in visited
    vector<bool> detected(g->getNumberOfNodes(), false);  // Nodes bei denen wir schon waren (effizienter als jedes Mal visited zu durchsuchen)

    // Start node hinzufügen
    visited.push_back(start);
    hops.push_back(0);
    detected.at(start) = true;

    // Nachbarn abgrasen
    int i = 0;  // Index im Visited Array des zu checkenden Nodes (beim ersten Mal ist es start)
    while (i < visited.size()) {
        for (const auto& neighbour : g->getNeighbours(visited.at(i))) {
            // Ziel gefunden
            if (neighbour == end) return hops.at(i) + 1;

            // Falls Node noch nicht gecheckt ist
            if (!detected.at(neighbour)) {
                // Füge zu den besuchten hinzu
                visited.push_back(neighbour);
                // Füge die Hops zu diesem Node hinzu
                hops.push_back(hops.at(i) + 1);
                // Setze auf besucht
                detected.at(neighbour) = true;
            }
        }
        i++; // Erhöhe index
    }

    return -1;
}

int main() {
    Graph g;
    g.randomInit();
    std::cout << g << std::endl;

    std::cout << minimumHops(&g, 7, 8) << std::endl;

    return 0;
}
