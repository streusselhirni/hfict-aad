//
// Created by Nicolas Haenni on 27.10.18.
//

#include <iostream>
#include <iomanip>
#include "Tree.h"

void Tree::insert(int value, Node* n) {
    if (n->data > value) {
        // insert left
        if (n->left == nullptr) {
            n->left = new Node();
            n->left->data = value;
        }
        else {
            this->insert(value, n->left);
        }
    }
    else {
        //insert right
        if (n->right == nullptr) {
            n->right = new Node();
            n->right->data = value;
        }
        else {
            this->insert(value, n->right);
        }
    }
}

void Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node();
        root->data = value;
        return;
    }
    this->insert(value, root);
}

void Tree::printInOrder() {
    if (root != nullptr) this->printInOrder(this->root);
}

void Tree::printInOrder(Node* n) {
    if (n->left != nullptr) this->printInOrder(n->left);
    std::cout << std::setw(4) << n->data;
    if (n->right != nullptr) this->printInOrder(n->right);
}

void Tree::printPreOrder() {
    if (this->root != nullptr) this->printPreOrder(this->root);
}

void Tree::printPreOrder(Node* n) {
    std::cout << std::setw(4) << n->data;
    if (n->left != nullptr) this->printPreOrder(n->left);
    if (n->right != nullptr) this->printPreOrder(n->right);
}

void Tree::printPostOrder() {
    if (this->root != nullptr) this->printPostOrder(this->root);
}

void Tree::printPostOrder(Node* n) {
    if (n->left != nullptr) this->printPostOrder(n->left);
    if (n->right != nullptr) this->printPostOrder(n->right);
    std::cout << std::setw(4) << n->data;
}
