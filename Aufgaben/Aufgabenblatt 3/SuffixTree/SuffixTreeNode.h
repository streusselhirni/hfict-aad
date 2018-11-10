//
// Created by Nicolas Haenni on 28.09.18.
//

#ifndef WOCHE_5_UND_6_SUFFIXTREENODE_H
#define WOCHE_5_UND_6_SUFFIXTREENODE_H

#define MAX_CHAR 256

struct SuffixTreeNode {
    struct SuffixTreeNode *children[MAX_CHAR];

    // pointer to other node via suffix link
    struct SuffixTreeNode *suffixLink;

    // (start, end( interval specifies the edge, by
    // which the node is connected to its parent node.
    // Each edge connect to nodes and (start, end) interval
    // is stored on child node.
    int start;
    int *end;

    // For leaf nodes, suffixIndex stores the index of suffix
    // for the path from root to leaf
    int suffixIndex;
};

#endif //WOCHE_5_UND_6_SUFFIXTREENODE_H
