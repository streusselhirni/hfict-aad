//
// Created by Nicolas Haenni on 09.11.18.
//
#include <iostream>
#include "BinaryTree.h"

int main() {
    Node* p = new Node();
    p->data = 5;
    std::cout << p->data << std::endl;
    delete p;
    std::cout << p->data << std::endl;
    p->data = 10;
    std::cout << p->data << std::endl;

    int *test = new int[5];
    for (int i = 0; i < 5; i++) {
        test[i] = i;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << test[i] << ", ";
    }
    delete []test;
    for (int i = 0; i < 5; i++) {
        std::cout << test[i] << ", ";
    }



    BinaryTree t;

    /*t.insert(25);
    t.insert(47);
    t.insert(17);
    t.insert(10);
    t.insert(19);
    t.insert(29);
    t.insert(26);
    t.insert(30);
    //t.remove(26);
    t.insert(82);
    //t.remove(25);
    //t.remove(17);*/

    t.insert(6);
    t.insert(3);
    t.insert(1);
    t.insert(5);
    t.insert(9);

    t.remove(1);

    t.printPostOrder();
    return 0;
}