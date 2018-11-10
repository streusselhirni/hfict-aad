//
// Created by Nicolas Haenni on 08.09.18.
//

#ifndef EX1_CONTAINER_ELEMENT_H
#define EX1_CONTAINER_ELEMENT_H

#include <iostream>

template<class T>
struct Element {
public:             // This is default anyway
    T data;
    Element *next = nullptr;
    Element();
    ~Element();
};

template<class T>
Element<T>::Element() {
    this->data = 0;
    this->next = nullptr;
}

template<class T>
Element<T>::~Element() {
    std::cout << "Element deleted." << std::endl;
}


#endif //EX1_CONTAINER_ELEMENT_H
