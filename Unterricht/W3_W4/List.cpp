//
// Created by Nicolas Haenni on 01.09.18.
//

#include <iostream>
#include "List.h"
#include "Element.h"

template<class T>
List<T>::List() : start(nullptr), end(nullptr), size(0) {}

template<class T>
List<T>::~List<T>() {
    Element<T> *iterator = start;
    while (iterator != nullptr) {
        Element<T> *tmp = iterator->next;
        delete iterator;
        iterator = tmp;
    }
    std::cout << "List deleted." << std::endl;
}

template<class T>
List<T>::List(const List &obj) {
    this->start = nullptr;
    this->end = nullptr;
    this->size = 0;

    Element<T> *iterator = obj.start;
    while (iterator != nullptr) {
        this->addElement(iterator->data);
        iterator = iterator->next;
    }
}

template<class T>
List<T> &List<T>::operator=(const List<T> &obj) {
    // TODO: Delete old data

    this->start = nullptr;
    this->end = nullptr;
    this->size = 0;

    Element<T> *iterator = obj.start;
    while (iterator != nullptr) {
        this->addElement(iterator->data);
        iterator = iterator->next;
    }

    return *this;
}

template<class T>
void List<T>::addElement(T value) {
    auto *obj = new Element<T>();
    obj->data = value;


    if (this->size == 0) {
        this->start = obj;

    }
    else {
        this->end->next = obj;
    }
    this->end = obj;
    this->size++;
}

template<class T>
void List<T>::insertElement(T value, int index) {
    Element<T> *before = nullptr;
    Element<T> *temp = start;
    auto *inserted = new Element<T>();
    inserted->data = value;

    for (int i(0); i < index; i++) {
        before = temp;
        temp = temp->next;
    }

    // If we insert at index = 0
    if (before == nullptr) this->start = inserted;
        // If we insert somewhere else
    else before->next = inserted;
    inserted->next = temp;
    this->size++;
}

template<class T>
T List<T>::get(int index) const {
    auto *temp = this->start;
    for (int i(0); i < index; i++) {
        temp = temp->next;
    }
    T value = temp->data;
    return value;
}

template<class T>
void List<T>::set(T value, int index) {
    Element<T> *temp = start;

    for (int i(0); i < index; i++) {
        temp = temp->next;
    }

    temp->data = value;
}

template<class T>
int List<T>::searchElement(T value, int startPos) { //NOLINT
    int index = 0;
    Element<T> *iterator = start;
    while (iterator != nullptr) {
        if (index >= startPos) {
            if (iterator->data == value) return index;
        }
        index++;
        iterator = iterator->next;
    }
    return -1;
}

template<class T>
bool List<T>::deleteElement(int index) {
    Element<T> *temp = start;
    Element<T> *before = start;
    Element<T> *after = temp->next;

    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Index out of bounds");
    }

    // If we delete first element
    if (index == 0) {
        start = after;
        delete temp;
        this->size--;
        return true;
    }

    // Set before, temp and after pointers to correct address
    for (int i(0); i < index; i++) {
        before = temp;      // Set before to current temp
        temp = temp->next;  // Set current temp to index that gets deleted
        after = temp->next; // Set after to index after the one that gets deleted
    }

    before->next = after;
    if (after == nullptr) this->end = before;
    delete temp;
    this->size--;

    return true;
}

template<class T>
int List<T>::length() const {
    return this->size;
}

template<class T>
bool List<T>::swap(int index1, int index2) {
    int tmp = this->get(index1);
    this->set(this->get(index2), index1);
    this->set(tmp, index2);
    return true;
}

template<class T>
void List<T>::print() const {
    Element<T> *temp = start;
    std::cout << std::endl;
    std::cout << "Size: " << this->length() << std::endl;
    std::cout << "Start: " << start << std::endl;
    for (int i(0); i < this->size; i++) {
        std::cout << "#" << i << "\t";
        std::cout << "My address: " << temp << "\t";
        std::cout << "Data: " << temp->data << "\t";
        std::cout << "Next: " << temp->next << std::endl;
        temp = temp->next;
    }
    std::cout << "End: " << end << std::endl;
    std::cout << std::endl;
}
