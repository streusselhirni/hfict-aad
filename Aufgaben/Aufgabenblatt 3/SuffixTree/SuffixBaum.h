//
// Created by Nicolas Haenni on 28.09.18.
//

#ifndef WOCHE_5_UND_6_SUFFIXBAUM_H
#define WOCHE_5_UND_6_SUFFIXBAUM_H

#include <string>
#include "./SuffixTreeNode.h"

class SuffixBaum {
private:
    char           *text; // Input String
    SuffixTreeNode *root;

    // last node created which may get a suffix link in next extension
    SuffixTreeNode *lastNewNode;

    // active Point (activeEdge is an input string index)
    SuffixTreeNode *activeNode;
    int            activeEdge;
    int            activeLength;

    int remainingSuffixCount;

    int leafEnd;
    int *rootEnd;
    int *splitEnd;
    int size; // Length of input string
    int size1; // Size of 1st string

    SuffixTreeNode *newNode(int start, int *end);
    void deleteSuffixTree(SuffixTreeNode *n);
    int edgeLength(SuffixTreeNode *n);
    int walkDown(SuffixTreeNode *currNode);
    void extendSuffixTree(int pos);
    void print(int i, int j);
    void setSuffixIndex(SuffixTreeNode *n, int labelHeight);
    void buildSuffixTree();
    int doTraversal(SuffixTreeNode *n, int labelHeight, int *maxHeight, int *substringStartIndex);
    void getLongestCommonSubstring();

public:
    SuffixBaum(std::string input1, std::string input2);
    ~SuffixBaum();
};


#endif //WOCHE_5_UND_6_SUFFIXBAUM_H
