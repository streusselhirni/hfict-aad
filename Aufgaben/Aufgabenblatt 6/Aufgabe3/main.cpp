//
// Created by Nicolas Haenni on 09.11.18.
//
#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <iomanip>
#include "../graph.h"

int getMinUnmarked(Graph* g, const std::vector<int>& distance, const std::vector<bool>& marked) {
    int           min = INT_MAX;
    unsigned long idx;

    // Gehe durch alle Nodes durch
    for (unsigned long i = 0; i < g->getNumberOfNodes(); i++) {
        // Wähle die aus, die noch nicht markiert sind und deren Distanz bisher die kleinste ist
        if (!marked.at(i) && distance.at(i) < min) {
            min = distance.at(i);
            idx = i;
        }
    }

    return static_cast<int>(idx);
}

std::map<std::string, std::vector<int>> dijkstra(Graph* g, unsigned long start) {
    std::vector<int>  distance(static_cast<unsigned long>(g->getNumberOfNodes()));
    std::vector<bool> marked(static_cast<unsigned long>(g->getNumberOfNodes()));
    std::vector<int>  predecessors(static_cast<unsigned long>(g->getNumberOfNodes()));
    int               numberOfNodes = g->getNumberOfNodes();

    // Initialisiere Vektoren
    for (unsigned long i = 0; i < numberOfNodes; i++) {
        distance.at(i)     = INT_MAX;
        marked.at(i)       = false;
        predecessors.at(i) = INT_MAX;
    }

    // Setze Distanz für start-Wert auf 0
    distance.at(start) = 0;

    for (unsigned long j = 0; j < numberOfNodes; j++) {
        // Wähle den nächsten Knoten aus
        int k = getMinUnmarked(g, distance, marked);

        // Wähle Nachbarn aus
        std::vector<int> neighbours = g->getNeighbours(k);
        std::vector<int> weights    = g->getWeights(k);

        // Gehe durch alle Nachbarn durch
        for (unsigned long i = 0; i < neighbours.size(); i++) {
            int tmp = neighbours.at(i);
            // Aber nur die, die noch nicht markiert sind
            if (!marked.at(tmp)) {
                // Fülle die neue Distanz ein, falls kleiner
                if (distance.at(k) + weights.at(i) < distance.at(tmp)) {
                    distance.at(tmp)     = distance.at(k) + weights.at(i);
                    predecessors.at(tmp) = k;
                }
            }
        }
        marked.at(k)         = true;
    }

    std::cout << "Dijkstra-Tabelle" << std::endl;
    for (int l = 0; l < numberOfNodes; l++) {
        std::cout << std::setw(4) << l;
        std::cout << std::setw(12) << distance.at(l);
        std::cout << std::setw(4) << marked.at(l);
        std::cout << std::setw(4) << predecessors.at(l);
        std::cout << std::endl;
    }

    std::map<std::string, std::vector<int>> result;
    result["distance"]    = distance;
    result["predecessor"] = predecessors;

    return result;
}

std::vector<int> getCheapestPath(Graph* g, int start, int end) {
    auto             d = dijkstra(g, start);
    std::vector<int> path;

    path.push_back(end);

    int last = end;
    while (last != start) {
        int tmp = d["predecessor"].at(last);
        path.push_back(tmp);
        last = tmp;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    Graph g;
    g.randomInit();

    std::vector<int> path = getCheapestPath(&g, 4, 1);

    for (auto c : path) {
        std::cout << "-->" << c;
    }


    std::cout << std::endl;

    std::cout << g << std::endl;
    return 0;
}
