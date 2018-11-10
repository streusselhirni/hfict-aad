//
// Created by Nicolas Haenni on 25.08.18.
//

#ifndef EX1_CONTAINER_CONTAINER_H
#define EX1_CONTAINER_CONTAINER_H

class Container {
public:
    virtual void addElement(int value) = 0;
    virtual void insertElement(int value, int index) = 0;
    virtual int get(int index) = 0;
    virtual void set(int value, int index) = 0;
    virtual int searchElement(int value, int startPos) = 0;
    virtual bool deleteElement(int index) = 0;
    virtual int length() = 0;
    virtual bool swap(int index1, int index2) = 0;
    virtual void print() = 0;
};


#endif //EX1_CONTAINER_CONTAINER_H
