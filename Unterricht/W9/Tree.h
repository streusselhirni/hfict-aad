//
// Created by Nicolas Haenni on 27.10.18.
//

#ifndef W9_TREE_H
#define W9_TREE_H

#include "Node.h"
#include <vector>

class Tree {
private:
    Node* root = nullptr;
    void insert(int value, Node* n);
    void printInOrder(Node* n);
    void printPreOrder(Node* n);
    void printPostOrder(Node* n);
    int count(Node* n);
    int height(Node* n);
    bool getPath(int sum, std::vector<int>& path, Node* n);
public:
    void insert(int value);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    int count();
    int height();
    std::vector<int> getPath(int sum);
};


#endif //W9_TREE_H
