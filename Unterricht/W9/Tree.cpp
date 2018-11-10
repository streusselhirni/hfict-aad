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
    std::cout << n->data << std::endl;
    if (n->right != nullptr) this->printInOrder(n->right);
}

void Tree::printPreOrder() {
    if (this->root != nullptr) this->printPreOrder(this->root);
}

void Tree::printPreOrder(Node* n) {
    std::cout << n->data << std::endl;
    if (n->left != nullptr) this->printPreOrder(n->left);
    if (n->right != nullptr) this->printPreOrder(n->right);
}

void Tree::printPostOrder() {
    if (this->root != nullptr) this->printPostOrder(this->root);
}

void Tree::printPostOrder(Node* n) {
    if (n->left != nullptr) this->printPostOrder(n->left);
    if (n->right != nullptr) this->printPostOrder(n->right);
    std::cout << n->data << std::endl;
}

/**
 * Returns the height of the tree.
 * @return
 */
int Tree::height(Node* n) {
    if (n == nullptr) return 0;

    int heightLeft  = 1 + this->height(n->left);
    int heightRight = 1 + this->height(n->right);

    if (heightLeft > heightRight) return heightLeft;
    return heightRight;
}

int Tree::height() {
    return this->height(root);
}

/**
 * Return a path from root to a leaf where the sum of all nodes
 * equals the parameter sum.
 * @param sum
 * @return Vector containing the nodes from root to leaf
 */

bool Tree::getPath(int sum, std::vector<int>& path, Node* n) {
    if (n == nullptr) return false;

    path.push_back(n->data);

    if (n->left == nullptr && n->right == nullptr) {
        // leaf node
        int lsum = 0;
        for (int c : path) {
            lsum += c;
        }
        if (lsum == sum) {
            // Solution found :-)
            return true;
        }
    }

    else {
        if (this->getPath(sum, path, n->left)) return true;
        if (this->getPath(sum, path, n->right)) return true;
    }

    path.pop_back();

    return false;
}

std::vector<int> Tree::getPath(int sum) {
    std::vector<int> path;
    this->getPath(sum, path, root);
    return path;
}

/**
 * Return number of nodes
 * @return
 */

int Tree::count(Node* n) {
    if (n == nullptr) return 0;
    return 1 + count(n->left) + count(n->right);
}

int Tree::count() {
    return count(this->root);
}

