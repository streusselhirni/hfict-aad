#include <iostream>
#include "./Array.h"

int main() {
    Array a;

    for (int i = 0; i < 25; ++i) {
        a.addElement(i);
    }

    a.insertElement(500, 10);

//    std::cout << a.searchElement(501) << std::endl;

    a.print();
    return 0;
}