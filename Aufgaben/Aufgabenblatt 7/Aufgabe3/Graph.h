//
// Created by Nicolas Haenni on 2019-01-11.
//

#ifndef WOCHE_9_UND_10_GRAPH_H
#define WOCHE_9_UND_10_GRAPH_H
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

class Graph {
    // Properties
private:
    std::vector<std::vector<int>> neighbours;
    std::vector<std::vector<int>> weights;

    // Methods
private:
    void dfs(int current, std::vector<int>& result, std::vector<bool>& detected);

public:
    Graph();
    void randomInit(int nNodes = 5, int nConnections = 8, bool directed = false);
    int getNumberOfNodes();
    std::vector<int> getNeighbours(int node);
    std::vector<int> getWeights(int node);
    void addNode(std::vector<int> neighbours, std::vector<int> weights);
    std::vector<int> dfs(int start);
    std::vector<int> bfs(int start);
    bool allNodesAreReachable(int start);
    int shortestReach(int start, int end);
    std::vector<int> getPath(int start, int end);
    bool checkGraphIsTree();

    friend std::ostream& operator<<(std::ostream& s, const Graph& obj);
};

std::ostream& operator<<(std::ostream& s, const Graph& obj);



#endif //WOCHE_9_UND_10_GRAPH_H
