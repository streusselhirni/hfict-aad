//
// Created by Nicolas Haenni on 17.11.18.
//

#ifndef W11_MAXHEAP_H
#define W11_MAXHEAP_H

#include <iostream>

class MaxHeap {
private:
    int * values;
    int currentSize;
    int maxSize;
    MaxHeap(const MaxHeap& obj);
    MaxHeap operator=(const MaxHeap& obj);
public:
    MaxHeap();
    ~MaxHeap();
    void insert(int n);
    int extractMax();
    void print() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << values[i] << ", ";
        }
        std::cout << std::endl;
    }
};

#endif //W11_MAXHEAP_H
