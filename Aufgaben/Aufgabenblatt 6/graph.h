//
// Created by Nicolas Haenni on 01.12.18.
//

#ifndef W13_GRAPH_H
#define W13_GRAPH_H

#include <vector>
#include <sstream>
using namespace std;

class Graph {
private:
    vector< vector<int> > neighbours;
    vector< vector<int> > weights;
public:
    Graph();
    void randomInit(int nNodes=10, int nConnections=15, bool directed=false);
    int getNumberOfNodes();
    vector<int> getNeighbours(int node);
    vector<int> getWeights(int node);
    void addNode(vector<int> neighbours, vector<int> weights);

    friend std::ostream& operator<<(std::ostream& s, const Graph & obj);
};

std::ostream& operator<<(std::ostream& s, const Graph & obj);


#endif //W13_GRAPH_H
