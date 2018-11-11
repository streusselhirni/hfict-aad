//
// Created by Nicolas Haenni on 10.11.18.
//

#ifndef WOCHE_9_UND_10_BINARYTREE_H
#define WOCHE_9_UND_10_BINARYTREE_H

#include <iostream>

class Node {
public:
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    ~Node() { std::cout << "Deleted element " << this->data << std::endl;}
};

class BinaryTree {
private:
    Node* root = nullptr;
    void insert(int value, Node* n);
    void remove(int value, Node* n);
    void printPostOrder(Node* n);
public:
    void insert(int value);
    void remove(int value);
    void printPostOrder();
};

#endif //WOCHE_9_UND_10_BINARYTREE_H
