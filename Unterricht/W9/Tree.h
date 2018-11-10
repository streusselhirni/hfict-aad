//
// Created by Nicolas Haenni on 27.10.18.
//

#ifndef W9_TREE_H
#define W9_TREE_H

#include "Node.h"

class Tree {
private:
    Node* root = nullptr;
    void insert (int value, Node* n);
    void printInOrder(Node* n);
    void printPreOrder(Node* n);
    void printPostOrder(Node* n);
public:
    void insert(int value);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};


#endif //W9_TREE_H
