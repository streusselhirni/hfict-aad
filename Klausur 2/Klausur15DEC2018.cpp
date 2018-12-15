#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<algorithm>
#include"KlausurUtils.h"

using namespace std;

// FUEGEN SIE FALLS NOETIG ABSOLUTE PFADE EIN
string aufgabe1_data    = "Aufgabe1.dat";
string aufgabe1_results = "Aufgabe1_Results.dat";
string aufgabe2_samples = "Aufgabe2_Samples.dat";
string aufgabe2_results = "Aufgabe2_Results.dat";
string aufgabe3_data    = "Aufgabe3.dat";
string aufgabe3_results = "Aufgabe3_Results.dat";

void methodeAufgabe1(vector<int>& input, vector<int>& output, int idx) {
    if (idx >= input.size()) return;
    output.push_back(input.at(idx));
    methodeAufgabe1(input, output, 2 * idx + 1);
    methodeAufgabe1(input, output, 2 * idx + 2);
}

string methodeAufgabe2(int idx) {
    // Create a binary tree with enough indeces
    const int   SIZE = 10000;
    vector<int> tree(SIZE);
    for (int    i    = 0; i < SIZE; i++) {
        tree.at(i);
    }

    // Prepare Path string
    string path;

    while (idx > 0) {
        // Get Parent
        int pIdx = (idx - 1) / 2;
        // Check if idx is left or right child
        if (idx == 2 * pIdx + 1) {
            // Left child
            path.append("L");
        }
        else {
            // Right child
            path.append("R");
        }
        // Continue searching up from parent
        idx = pIdx;
    }
    // Reverse the Path as we went backwards when creating it
    reverse(path.begin(), path.end());
    return path;
}

// Source of this function: Lecture with D. Herzig
void bfs(vector<vector<int>> g, vector<int>& result, int next) {
    // Cancel if next node would be out of bounds
    if (next >= result.size()) {
        return;
    }

    // Loop through neighbours
    for (auto n : g.at(result.at(next))) {
        // If node is not yet visited
        if (find(result.begin(), result.end(), n) == result.end()) {
            // Add it to result of bfs traversal
            result.push_back(n);
        }
    }
    bfs(g, result, ++next);
}

vector<int> methodeAufgabe3(vector<vector<int>>& data) {

    int         idx     = 0;    // Keep track of which index to process
    int         subSize = 0;    // Keep track of size of biggest sub graph
    vector<int> subGraph;       // Keep track of biggest sub graph
    vector<int> visited;        // Keep track of visited nodes

    // Loop through graph
    while (idx < data.size()) {
        // If we have not yes visited idx and current node has neighbours
        if (find(visited.begin(), visited.end(), idx) == visited.end() && data.at(idx).size() > 0) {
            // Add current node to visited nodes
            visited.push_back(idx);
            // Initialize vector to store temporary result for bfs
            vector<int> res;
            // Push initial node
            res.push_back(idx);
            // Run bfs, result is stored in res
            bfs(data, res, 0);
            // Add nodes which have been visited during bfs to visited vector
            visited.insert(visited.end(), res.begin(), res.end());
            // Check if result of bfs is bigger then the last bfs results
            // If yes, store it
            if (res.size() > subSize) {
                subSize  = res.size();
                subGraph = res;
            }
        }

        // Increment index to continue
        idx++;
    }

    return subGraph; // REPLACE WITH CORRECT RETURN COMMAND
}

int main() {
    /*********************************************************
     * Aufgabe 1 - DFS Search on Binary Tree
     *********************************************************/

    cout << "AUFGABE 1 - RESULTATE" << endl;
    cout << "=====================" << endl;
    vector<int> data1    = *(KlausurUtils::getDataVector(aufgabe1_data));
    vector<int> results1 = *(KlausurUtils::getDataVector(aufgabe1_results));
    vector<int> output   = vector<int>(0);
    methodeAufgabe1(data1, output, 0);
    cout << "[CHECK -> " << (output.size() == results1.size() && output == results1 ? "PASSED" : "FAILED")
         << "] - Size of Output Vector: '" << output.size()
         << "' - Size of Result Vector: '" << results1.size() << "'" << endl
         << "                 "
         << " - First 10 and last 10 items in input vector: "
         << KlausurUtils::vectorToString(data1, 10, 10) << endl
         << "                 "
         << " - First 10 and last 10 items in calculated result vector: "
         << KlausurUtils::vectorToString(output, 10, 10) << endl
         << "                 "
         << " - First 10 and last 10 items in expected result vector: "
         << KlausurUtils::vectorToString(results1, 10, 10) << endl;

    /*********************************************************
     * Aufgabe 2 - Should I go Left or Right ?
     *********************************************************/

    cout << endl << endl << "AUFGABE 2 - RESULTATE" << endl;
    cout << "=====================" << endl;
    vector<int>         samples2 = *(KlausurUtils::getDataVector(aufgabe2_samples));
    vector<vector<int>> results2 = KlausurUtils::get2dDataVector(aufgabe2_results);
    int                 i2       = 0;
    for (int& data2 : samples2) {
        string      output2 = methodeAufgabe2(data2);
        vector<int> v2      = results2[i2++];
        string      result2 = string(v2.begin(), v2.end());
        cout << "[CHECK -> " << ((output2 == result2) ? "PASSED" : "FAILED")
             << "] - Method Input: '" << data2
             << "' - Method Output: '" << output2
             << "' - Expected Result: '" << result2 << "'" << endl;
    }

    /*********************************************************
     * Aufgabe 3 - Extract Biggest Sub-Graph (Component)
     *********************************************************/

    cout << endl << endl << "AUFGABE 3 - RESULTATE" << endl;
    cout << "=====================" << endl;
    vector<vector<int>> data3   = KlausurUtils::get2dDataVector(aufgabe3_data);
    vector<int>         result3 = *(KlausurUtils::getDataVector(aufgabe3_results));
    vector<int>         output3 = methodeAufgabe3(data3);
    cout << "[CHECK -> " << ((output3 == result3) ? "PASSED" : "FAILED")
         << "] - Method Output: " << KlausurUtils::vectorToString(output3) << endl
         << "                  "
         << "- Expected Result: " << KlausurUtils::vectorToString(result3) << endl;

    return 0;
}