//
// Created by Nicolas Haenni on 08.09.18.
//

#include <iostream>
#include "Element.h"

template<class T>
Element<T>::Element() {
    this->data = 0;
    this->next = nullptr;
}

template<class T>
Element<T>::~Element() {
    std::cout << "Element deleted." << std::endl;
}
