#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include "graph.h"

using namespace std;

void dfs(Graph* g, int current, set<int>& grassedNodes) {
    if (grassedNodes.find(current) != grassedNodes.end()) return;
    grassedNodes.insert(current);
    cout << current << ",";
    vector<int> neighbours = g->getNeighbours(current);
    for (int    n : neighbours) {
        dfs(g, n, grassedNodes);
    }
}

void bfs(Graph* g, vector<int>& result, int next) {
    if (next >= result.size()) {
        return;
    }
    for (auto n : g->getNeighbours(result.at((unsigned long) next))) {
        if (find(result.begin(), result.end(), n) == result.end()) {
            result.push_back(n);
        }
    }
    bfs(g, result, ++next);
}

void dfs(Graph* g, int start) {
    set<int> grassedNodes;
    dfs(g, start, grassedNodes);
    cout << endl;
}

vector<int> bfs(Graph* g, int start) {
    vector<int> result;
    result.push_back(start);
    bfs(g, result, 0);
    return result;
}

bool pathExists(Graph* g, int start, int target) {
    vector<int> bfsRes = bfs(g, start);
    return find(bfsRes.begin(), bfsRes.end(), target) != bfsRes.end();
}

vector<int> getSinkNodes(Graph* g) {
    vector<int> sinkNodes;
    for (int    n = 0; n < g->getNumberOfNodes(); n++) {
        if (empty(g->getNeighbours(n))) {
            sinkNodes.push_back(n);
        }
    }
    return sinkNodes;
}

vector<int> getSourceNodes(Graph* g) {
    vector<int> sourceNodes;
    set<int> nSet;
    for (int i = 0; i < g->getNumberOfNodes(); i++) {
        nSet.insert(i);
    }

    for (int j = 0; j < g->getNumberOfNodes(); j++) {
        for (auto n : g->getNeighbours(j)) {
            if (find(nSet.begin(), nSet.end(), n) == nSet.end()) {
                sourceNodes.push_back(n);
            }
        }
    }

    return sourceNodes;
}

int main(int argc, char** argv) {

    srand(10);
    Graph g;
    g.randomInit(20, 30, true);
    cout << g << endl;

    vector<int> sn = getSourceNodes(&g);
    for (auto n : sn) {
        cout << n << ", ";
    }
    return 0;
}

