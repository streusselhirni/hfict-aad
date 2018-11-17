//
// Created by Nicolas Haenni on 17.11.18.
//

#include "MaxHeap.h"

MaxHeap::MaxHeap() : currentSize(0), maxSize(10000) {
    values = new int[10000];
}

MaxHeap::~MaxHeap() {
    delete []values;
}

// parent = (index - 1) / 2
// left = index * 2 + 1
// right = index * 2 + 2
void MaxHeap::insert(int n) {
    // Insert
    values[currentSize] = n;
    // Bubble up
    int current = currentSize;
    int parent = (current - 1) / 2;
    while(current != 0 && values[current] > values[parent]) {
        int tmp = values[current];
        values[current] = values[parent];
        values[parent] = tmp;
        current = parent;
        parent = (current - 1) / 2;
    }
    currentSize++;
}

int MaxHeap::extractMax() {
    // is empty check
    int result = values[0];
    currentSize--;
    int current = 0;
    int swapIdx;
    values[current] = values[currentSize];
    // bubble down
    while (currentSize > 1) {
        int left  = current * 2 + 1;
        int right = current * 2 + 2;
        if (values[left] > values[right]) {
            // left
            swapIdx = left;
        }
        else {
            // right
            swapIdx = right;
        }
        int tmp = values[current];
        values[current] = values[swapIdx];
        values[swapIdx] = tmp;
    }

    return result;
}
