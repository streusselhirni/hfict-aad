//
// Created by Nicolas Haenni on 17.11.18.
//

#ifndef W11_PROCESSLIST_H
#define W11_PROCESSLIST_H

#include <list>

class ProcessList {
private:
    std::list<int> data;
public:
    void insert(int n);
    int next(bool& ok);
    int size();

    friend std::ostream& operator<<(std::ostream& stream, const ProcessList& obj);
};

#endif //W11_PROCESSLIST_H
