//
// Created by Nicolas Haenni on 28.09.18.
//

#include <iostream>
#include "SuffixBaum.h"

#define MAX_CHAR 256

SuffixBaum::SuffixBaum(std::string input1, std::string input2) : root(nullptr), lastNewNode(nullptr),
                                                                 activeNode(nullptr), activeEdge(-1),
                                                                 activeLength(0), remainingSuffixCount(0), leafEnd(-1),
                                                                 rootEnd(nullptr), splitEnd(nullptr),
                                                                 size(-1), size1(-1) {
    std::string tmp = input1 + "#" + input2 + "$";
    this->text = new char[tmp.size()];
    strcpy(text, tmp.c_str());

    this->buildSuffixTree();
    this->getLongestCommonSubstring();
}

/**
 * Creates a new Node in the Tree
 * @param start - The input character string index of the first character on the
 * path from its parent to this node
 * @param end - The input character string index of the last character on the path
 * from its parent to this node
 * @return - A pointer to the newly created node
 */
SuffixTreeNode *SuffixBaum::newNode(int start, int *end) {
    auto node = new SuffixTreeNode;

    for (int i = 0; i < MAX_CHAR; i++) {
        node->children[i] = nullptr;
    }

    node->suffixLink = root;
    node->start      = start;
    node->end        = end;

    // suffixIndex (the number of the suffix this leaf contains)
    // will be set to -1 (no leaf, no suffix) by default and
    // actual suffix index will be set later for leaves
    node->suffixIndex = -1;
    return node;
}

/**
 * Counts the length of the edge from its parent to Node n
 * @param n - Node whose leaf should be counted
 * @return - The number of characters on the edge from its parent to this node
 */
int SuffixBaum::edgeLength(SuffixTreeNode *n) {
    if (n == root) return 0;
    return *(n->end) - (n->start) + 1;
}

/**
 * Walk down the tree using the count/skip trick. If the activeLength (from activePoint) is greater
 * than the edge to the node, change activePoint to be counting from currNode.
 * @param currNode - Node to start from to walk down
 * @return - 0 when walk down not necessary, 1 when walk down successful
 */
int SuffixBaum::walkDown(SuffixTreeNode *currNode) {
    // activePoint change for walk down. If activeLength is
    // greater than current edge length, set next interval
    // node as activeNode and adjust activeEdge and activeLength
    // accordingly to represent same activePoint
    if (activeLength >= edgeLength(currNode)) {
        activeEdge += edgeLength(currNode);
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}

/**
 * Takes care of the phases and extensions necessary to extend the suffixTree
 * @param pos - Position index of input string character for which the suffixes
 * need to be added
 */
void SuffixBaum::extendSuffixTree(int pos) {
    // Extension rule 1: If the path from the root labelled
    // S[j..i] ends at leaf edge (i.e. S[i] is last character
    // on leaf edge) then character S[i+1] is just added to the
    // end of the label on that leaf edge.
    // Does all extensions from 1 to i for character i.
    // For pos = 3 ('abc'): To be added 'abc', 'bc', 'c'; already added: 'a', 'ab')
    // 'c' just need to be added to the already existing paths
    leafEnd = pos;

    // Increment remainingSuffixCount to show that a new suffix
    // is yet to be added to the tree (eg. 'c')
    remainingSuffixCount++;

    // Set lastNewNode to nullptr while starting a new phase
    // to show that there is no internal node waiting for
    // it's suffix link to be reset in current phase
    lastNewNode = nullptr;

    while (remainingSuffixCount > 0) {
        // active point change for activeLength zero
        if (activeLength == 0) activeEdge = pos;

        // If there is no outgoing edge starting with activeEdge
        // from activeNode
        if (activeNode->children[text[activeEdge]] == nullptr) {
            // Rule 2: New leaf edge gets created starting from an
            // existing node (activeNode)
            activeNode->children[text[activeEdge]] =
                    newNode(pos, &leafEnd);

            // If there is an internal node waiting for it's suffix
            // link to be set, point the suffix link from that last
            // internal node to current activeNode. Then set lastNewNode
            // tp nullptr to show that no more nodes are waiting for
            // suffix link reset
            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = nullptr;
            }
        }
            // If there is an outgoing edge starting with activeEdge from
            // activeNode
        else {
            // Get the next node at the end of edge starting with activeEdge
            SuffixTreeNode *next = activeNode->children[text[activeEdge]];

            if (walkDown(next)) { // Do walk down
                // If walk down was successfull (activeLength < edgeLength)
                // go to next extension
                continue;
            }
            // Rule 3 (current character being processes is already on edge
            if (text[next->start + activeLength] == text[pos]) {
                // If a newly created node is waiting for it's suffixLink
                // to be set, then set it to current activeNode
                if (lastNewNode != nullptr && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }

                // active point change for extension rule 3: The activePoint
                // is incremented because we used rule 3 (Suffix is already implicitly in tree)
                activeLength++;

                // Stop all further processing in this phase and move to next
                // phase
                break;
            }

            // We will be here when activePoint is in middle of an edge being
            // traversed and current character is not on the edge. In this case
            // we add a new internal node and a new leaf edge going of of that
            // node. This is extension rule 2.
            splitEnd = new int;
            *splitEnd = next->start + activeLength - 1;

            // New internal node
            auto *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;

            // New leaf coming out of internal node
            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;

            // If there is an internal node created in last extensions of same
            // phase which is still waiting for its suffix link to be set, do it
            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = split;
            }

            // Make the current newly created internal node wait for it's suffix
            // link to be set.
            lastNewNode = split;
        }

        // A suffix got added in tree, decrement the count of suffixed yet to be added
        remainingSuffixCount--;
        // activePoint change for extension rule 2 c1
        if (activeNode == root && activeLength > 0) {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        }
        else if (activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

/**
 * Print the characters from index i to j
 * @param i - Input string character index to start from
 * @param j - Input string character index to print to
 */
void SuffixBaum::print(int i, int j) {
    int k;
    for (k = i; k <= j && text[k] != '#'; k++) {
        std::cout << text[k];
    }
    if (k <= j) printf("#");
}

void SuffixBaum::setSuffixIndex(SuffixTreeNode *n, int labelHeight) {
    if (n == nullptr) return;

    if (n->start != -1) { // A non-root node
        // Print the label on edge from parent to current node
        //  this->print(n->start, *(n->end));
    }

    int leaf = 1;
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        // If all children are nullptr, we are on a leaf
        if (n->children[i] != nullptr) {
            // This is no leaf
            // Print suffix index (uncomment if necessary)
            // if (leaf == 1 && n->start != -1) {
            // std::cout << " " << n->suffixIndex << std::endl;
            // }

            // Since current node is not a leaf as it has outgoing edges from it
            leaf = 0;
            // Check children of current node
            this->setSuffixIndex(n->children[i],
                                labelHeight + edgeLength(n->children[i]));
        }
    }
    if (leaf == 1) {
        // We are on a leaf
        for (i = n->start; i <= *(n->end); i++) {
            if (text[i] == '#') {
                n->end = new int;
                *(n->end) = i;
            }
        }
        n->suffixIndex = size - labelHeight;
        // Print suffix index
        // printf(" [%d]\n", n->suffixIndex);
    }
}

SuffixBaum::~SuffixBaum() {
    if (root != nullptr) this->deleteSuffixTree(root);
}

void SuffixBaum::deleteSuffixTree(SuffixTreeNode *n) {
    int i;

    for (i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != nullptr) {
            delete (n->children[i]);
        }
    }

    if (n->suffixIndex == -1) {
        delete (n->end);
    }
}

void SuffixBaum::buildSuffixTree() {
    size = strlen(text);
    int i;
    rootEnd = new int;
    *rootEnd = 01;

    // Root is a specual node with stat and end indices as
    // -1 as it has no parent
    root = newNode(-1, rootEnd);

    activeNode = root; // First activeNode will be root
    for (i     = 0; i < size; i++) {
        extendSuffixTree(i);
    }
    int labelHeight = 0;
    this->setSuffixIndex(root, labelHeight);
}

int SuffixBaum::doTraversal(SuffixTreeNode *n, int labelHeight, int *maxHeight, int *substringStartIndex) {
    if (n == nullptr) {
        return 0;
    }
    int i   = 0;
    int ret = -1;
    if (n->suffixIndex < 0) { // If it is internal node
        for (i = 0; i < MAX_CHAR; i++) {
            if (n->children[i] != nullptr) {
                ret = doTraversal(n->children[i],
                                  labelHeight + edgeLength(n->children[i]),
                                  maxHeight, substringStartIndex);
                if (n->suffixIndex == -1) n->suffixIndex = ret;
                else if ((n->suffixIndex == -2 && ret == -3) ||
                         (n->suffixIndex == -3 && ret == -2) ||
                         n->suffixIndex == -4) {
                    n->suffixIndex = -4; // Mark node as XY
                    if (*maxHeight < labelHeight) {
                        *maxHeight           = labelHeight;
                        *substringStartIndex = *(n->end) - labelHeight + 1;
                    }
                }
            }
        }
    }
    else if (n->suffixIndex > -1 && n->suffixIndex < size1) {
        return -2; // Mark node as X
    }
    else if (n->suffixIndex >= size1) { //Suffix of Y
        return -3; // Mark node as Y
    }
    return n->suffixIndex;
}

void SuffixBaum::getLongestCommonSubstring() {
    int maxHeight           = 0;
    int substringStartIndex = 0;
    doTraversal(root, 0, &maxHeight, &substringStartIndex);

    int k;
    for (k = 0; k < maxHeight; k++) {
        printf("%c", text[k + substringStartIndex]);
    }
    if (k == 0) printf("No common substring");
    else printf("\n(length: %d)", maxHeight);
    printf("\n");
}
