//
// Created by Nicolas Haenni on 2019-01-11.
//

#include "Graph.h"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

Graph::Graph() {}

void Graph::addNode(std::vector<int> neighbours, std::vector<int> weights) {
    this->neighbours.push_back(neighbours);
    this->weights.push_back(weights);
}

void Graph::randomInit(int nNodes, int nConnections, bool directed) {
    std::vector<int> v;
    for (int i = 0; i < nNodes; i++) {
        neighbours.push_back(v);
    }
    int counter = 0;
    int max = nConnections * 5;
    while (counter < nConnections || counter > max) {
        int source = rand() % nNodes;
        int target = rand() % nNodes;
        if (source != target) {
            if (find(neighbours[source].begin(), neighbours[source].end(), target) ==
                neighbours[source].end()) {
                neighbours[source].push_back(target);
                if (!directed) {
                    neighbours[target].push_back(source);
                }
                counter++;
            }
        }
    }
    for (int i = 0; i < nNodes; i++) {
        sort(neighbours[i].begin(), neighbours[i].end());
    }

    for (std::vector<int> v : neighbours) {
        std::vector<int> w;
        for (int i = 0; i < v.size(); i++) {
            int cost = rand() % 20 + 1;
            w.push_back(cost);
        }
        weights.push_back(w);
    }

    if (!directed) {
        for (int i = 0; i < weights.size(); i++) {
            for (int j = 0; j < weights.at(i).size(); j++) {
                int source = i;
                int target = neighbours.at(i).at(j);
                int weight = weights.at(i).at(j);
                int index = find(neighbours.at(target).begin(),
                                 neighbours.at(target).end(), source) -
                            neighbours.at(target).begin();
                weights[target][index] = weight;
            }
        }
    }
}

int Graph::getNumberOfNodes() { return neighbours.size(); }

std::vector<int> Graph::getNeighbours(int node) { return neighbours.at(node); }

std::vector<int> Graph::getWeights(int node) { return weights.at(node); }

std::ostream& operator<<(std::ostream& s, const Graph& obj) {
    for (int i = 0; i < obj.neighbours.size(); i++) {
        std::vector<int>::iterator it;
        s << "Node " << i << "\t";
        for (int j = 0; j < obj.neighbours[i].size(); j++) {
            s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
        }
        s << endl;
    }
    return s;
}

std::vector<int> Graph::dfs(int start) {
    std::vector<int> result;
    std::vector<bool> detected(getNumberOfNodes(), false);
    dfs(start, result, detected);
    return result;
}

void Graph::dfs(int current, std::vector<int>& result, std::vector<bool>& detected) {
    // break condition
    if (detected.at(current)) return;

    // process node
    result.push_back(current);
    detected.at(current) = true;

    // process neighbours
    for (const auto& neighbour : neighbours.at(current)) {
        dfs(neighbour, result, detected);
    }
}

std::vector<int> Graph::bfs(int start) {
    // Init
    std::vector<int> result;                                // result std::vector
    std::vector<bool> detected(getNumberOfNodes(), false);  // track detected nodes

    // Add start
    result.push_back(start);
    detected.at(start) = true;

    // Loop neighbours
    int i = 0;  // index of next node to process
    while (i < result.size()) {
        for (const auto& neighbour : neighbours.at(result.at(i))) {
            if (!detected.at(neighbour)) {
                result.push_back(neighbour);
                detected.at(neighbour) = true;
            }
        }
        i++;
    }

    return result;
}

bool Graph::allNodesAreReachable(int start) {
    return bfs(start).size() == getNumberOfNodes();
}

int Graph::shortestReach(int start, int end) {
    // return 0 if start and end are the same
    if (start == end) return 0;

    // Init
    std::vector<int> visited;  // processed nodes
    std::vector<int> hops;     // number of hops to visited node
    std::vector<bool> detected(getNumberOfNodes(), false);  // tracks detected nodes

    // Add start node
    visited.push_back(start);
    hops.push_back(0);
    detected.at(start) = true;

    // Loop neighbours
    int i = 0;  // index of next node to process
    while (i < visited.size()) {
        for (const auto& neighbour : getNeighbours(visited.at(i))) {
            // end node found
            if (neighbour == end) return hops.at(i) + 1;

            // add neighbours
            if (!detected.at(neighbour)) {
                visited.push_back(neighbour);
                hops.push_back(hops.at(i) + 1);
                detected.at(neighbour) = true;
            }
        }
        i++;
    }

    return -1;
}

std::vector<int> Graph::getPath(int start, int end) {
    // validate params
    std::vector<int> result;
    if (start < 0 || start >= getNumberOfNodes()) return result;
    if (end < 0 || end >= getNumberOfNodes()) return result;
    if (start == end) {
        result.push_back(start);
        return result;
    }

    // initialize table
    std::vector<int> distance(getNumberOfNodes(), INT_MAX);
    typedef pair<int, int> intPair;
    priority_queue<intPair, std::vector<intPair>, greater<intPair>> prioQueue;
    std::vector<bool> marked(getNumberOfNodes(), false);
    std::vector<int> predecessor(getNumberOfNodes(), -1);

    // write start node to table
    distance.at(start) = 0;
    prioQueue.push(make_pair(0, start));
    predecessor.at(start) = start;

    // process path
    while (!prioQueue.empty()) {
        int current = prioQueue.top().second;
        prioQueue.pop();
        if (marked.at(current)) continue;
        marked.at(current) = true;

        std::vector<int> neighbours = getNeighbours(current);
        std::vector<int> weights = getWeights(current);

        for (int i = 0; i < neighbours.size(); i++) {
            int neighbour = neighbours.at(i);
            if (marked.at(neighbour)) continue;
            int newDist = distance.at(current) + weights.at(i);
            if (newDist < distance.at(neighbour)) {
                distance.at(neighbour) = newDist;
                prioQueue.push(make_pair(newDist, neighbour));
                predecessor.at(neighbour) = current;
            }
        }
    }

    // return shortest path
    if (predecessor.at(end) != -1) {  // fill result only if end is reachable
        result.push_back(end);
        int prev = predecessor.at(end);
        while (prev != start) {
            result.push_back(prev);
            prev = predecessor.at(prev);
        }
        result.push_back(start);
    }
    reverse(result.begin(), result.end());
    return result;
}

bool Graph::checkGraphIsTree() {
    // Init
    std::vector<int> traversal;                       // traversal std::vector
    std::vector<int> parent(getNumberOfNodes(), -1);  // store parent of node

    // Add start
    traversal.push_back(0);
    parent.at(0) = 0;

    // Loop neighbours
    for (int i = 0; i < traversal.size(); i++) {
        int current = traversal.at(i);
        for (const auto& neighbour : neighbours.at(current)) {
            if (parent.at(neighbour) == -1) {
                traversal.push_back(neighbour);
                parent.at(neighbour) = current;
            } else if (neighbour != parent.at(current)) {
                return false;
            }
        }
    }

    return true;
}