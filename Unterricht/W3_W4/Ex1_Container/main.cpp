#include <iostream>
#include "./Array.h"
#include "./List.h"

int main() {
    auto list = new List<int>();

    for (int i(0); i < 10; i++) {
        list->addElement(100 + i);
    }

    try {
        list->deleteElement(5);
        std::cout << list->get(2) << std::endl;
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    list->print();
    return 0;
}