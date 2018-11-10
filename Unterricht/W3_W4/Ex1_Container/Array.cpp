//
// Created by Nicolas Haenni on 25.08.18.
//

#include <iostream>
#include "Array.h"

Array::Array() {
    values = new int[10];
    maxSize = 10;
    currentSize = 0;
}

void Array::checkSize() {
    bool check = false;
    if (currentSize > maxSize) {
        maxSize *= 2;
        check = true;
    } else if (currentSize < maxSize / 4) {
        maxSize /= 2;
        check = true;
    }
    if (check) {
        int *tmp = new int[maxSize];
        for (int i(0); i < currentSize; i++) {
            tmp[i] = values[i];
        }
        delete values;
        values = tmp;
    }
}

void Array::addElement(int value) {
    currentSize++;
    checkSize();
    values[currentSize - 1] = value;
}

void Array::insertElement(int value, int index) {
    currentSize++;
    checkSize();
    for (int i(currentSize); i >= index; i--) {
        values[i] = values[i - 1];
    }
    values[index] = value;
}

int Array::get(int index) const {
    return values[index];
}

void Array::set(int value, int index) {
    values[index] = value;
}

int Array::searchElement(int value, int startPos) {
    for (int i(startPos); i < currentSize; i++) {
        if (values[i] == value) {
            return i;
        }
    }
    return -1;
}

bool Array::deleteElement(int index) {
    if (index > currentSize || index < 0) {
        return false;
    }
    currentSize--;
    for (int i = currentSize; i >= 0 ; i--) {
        values[i - 1] = values[i];
    }
    return true;
}

int Array::length() {
    return currentSize + 1;
}

bool Array::swap(int index1, int index2) {
    if (index1 > currentSize || index2 > currentSize || index1 < 0 || index2 < 0) {
        return false;
    }

    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
    return true;
}

void Array::print() {
    for (int i(0); i < currentSize; i++) {
        std::cout << values[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "maxSize: " << maxSize << std::endl;
    std::cout << "currentSize: " << currentSize << std::endl;
}
