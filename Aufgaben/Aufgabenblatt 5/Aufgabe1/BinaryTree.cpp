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
            n->left       = new Node();
            n->left->data = value;
        }
        else {
            this->insert(value, n->left);
        }
    }
    else {
        //insert right
        if (n->right == nullptr) {
            n->right       = new Node();
            n->right->data = value;
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

    if (n->left->data == value) {
        if (n->left->left == nullptr && n->left->right == nullptr) {
            // leaf node
            delete n->left;
            n->left = nullptr;
            return;
        }
        if (n->left->left != nullptr && n->left->right != nullptr) {
            // there are two children
            return;
        }


        // only one child
        if (n->left->left != nullptr) {
            Node* tmp = n->left->left;
            delete n->left;
            n->left = tmp;
            return;
        }
        if (n->left->right != nullptr) {
            Node* tmp = n->left->right;
            delete n->left;
            n->left   = tmp;
            return;
        }
        if (n->right->left != nullptr) {
            Node* tmp = n->right->left;
            delete n->right;
            n->right  = tmp;
            return;
        }
        if (n->right->right != nullptr) {
            Node* tmp = n->right->right;
            delete n->right;
            n->right  = tmp;
            return;
        }

    }
    if (n->right->data == value) {
        if (n->right->left == nullptr && n->right->right == nullptr) {
            // leaf node
            delete n->right;
            n->right = nullptr;
            return;
        }
    }
    else {
        this->remove(value, n->left);
        this->remove(value, n->right);
    }


//    if (n->data == value) {
//        if (n->left == nullptr && n->right == nullptr) {
//            // leaf node
//            delete n;
//            return;
//        }
//        if (n->left != nullptr && n->right != nullptr) {}
//        if (n->left == nullptr || n->right == nullptr) {
//            // there is only one child
//            if (n->left != nullptr) {
//                // there is only left child
//                Node* tmp = n->left;
//                delete n;
//                n = tmp;
//            }
//        }
//    }
//    else {
//        this->remove(value, n->left);
//        this->remove(value, n->right);
//    }
}
