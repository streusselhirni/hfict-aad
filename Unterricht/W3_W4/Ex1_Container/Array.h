//
// Created by Nicolas Haenni on 25.08.18.
//

#ifndef EX1_CONTAINER_ARRAY_H
#define EX1_CONTAINER_ARRAY_H


#include "Container.h"

class Array : public Container<int> {
private:
    int *values;
    int maxSize;
    int currentSize;

    void checkSize();
public:
    Array();
    virtual void addElement(int value);
    virtual void insertElement(int value, int index);
    virtual int get(int index) const;
    virtual void set(int value, int index);
    virtual int searchElement(int value, int startPos = 0);
    virtual bool deleteElement(int index);
    virtual int length();
    virtual bool swap(int index1, int index2);
    virtual void print();
};


#endif //EX1_CONTAINER_ARRAY_H
