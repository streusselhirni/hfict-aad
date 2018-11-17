//
// Created by Nicolas Haenni on 17.11.18.
//

#include "ProcessList.h"
#include <iostream>

int ProcessList::size() {
    return static_cast<int>(this->data.size());
}

void ProcessList::insert(int n) {
    std::list<int>::iterator it;
    for (it = this->data.begin(); it != this->data.end(); it++) {
        if (*it < n) {
            this->data.insert(it, n);
            return;
        }
    }
    this->data.push_back(n);
}

std::ostream& operator<<(std::ostream& out, const ProcessList& obj) {
    for (int value : obj.data) {
        out << value << ",";
    }
    return out;
}

int ProcessList::next(bool& ok) {
    if (!this->data.empty()) {
        int n = this->data.front();
        this->data.pop_front();
        ok = true;
        return n;
    }
    ok = false;
    return -1;
}