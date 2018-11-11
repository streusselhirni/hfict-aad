//
// Created by Nicolas Haenni on 10.11.18.
//

#include <iostream>
#include "BinaryTree.h"

void BinaryTree::insert(int value) {
    if (this->root == nullptr) {
        this->root       = new Node();
        this->root->data = value;
        return;
    }
    this->insert(value, this->root);
}

void BinaryTree::insert(int value, Node* n) {
    if (n->data > value) {
        // insert left
        if (n->left == nullptr) {
            n->left         = new Node();
            n->left->data   = value;
        }
        else {
            this->insert(value, n->left);
        }
    }
    else {
        //insert right
        if (n->right == nullptr) {
            n->right         = new Node();
            n->right->data   = value;
        }
        else {
            this->insert(value, n->right);
        }
    }
}

void BinaryTree::printPostOrder() {
    if (this->root != nullptr) this->printPostOrder(this->root);
}

void BinaryTree::printPostOrder(Node* n) {
    if (n->left != nullptr) this->printPostOrder(n->left);
    if (n->right != nullptr) this->printPostOrder(n->right);
    std::cout << n->data << std::endl;
}

void BinaryTree::remove(int value) {
    if (this->root != nullptr) this->remove(value, this->root);
}

void BinaryTree::remove(int value, Node* n) {
    if (n == nullptr) return;

    if (n->data == value) {
        if (n->left == nullptr && n->right == nullptr) {
            // leaf node
            delete n;
        }
        else {
            if (n->left != nullptr || n->right != nullptr) {
                // there is only one child
                if (n->left != nullptr) {
                    // there is only left child
                    Node* tmp = n->left;
                    delete n;
                    n = tmp;
                }
            }
        }
    }
    else {
        this->remove(value, n->left);
        this->remove(value, n->right);
    }
}
