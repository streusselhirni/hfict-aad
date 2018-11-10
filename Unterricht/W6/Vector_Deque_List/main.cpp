#include <iostream>
#include <vector>
#include <list>
#include <ctime>

int main() {
    clock_t vstart, vstop, lstart, lstop;

    std::vector<int> v;
    std::list<int> l;

    const int N = 10000000;

    srand(5);

    vstart = clock();
    for (int i = 0; i < N; i++) {
        v.push_back(rand());
    }
    vstop = clock();

    lstart = clock();
    for (int i = 0; i < N; i++) {
        l.push_back(rand());
    }
    lstop = clock();

    std::cout << "Push_Back Vector:\t" << ((double) (vstop - vstart) / CLOCKS_PER_SEC)
              << " Sekunden." << std::endl;
    std::cout << "Push_Back List:\t" << (double) (lstop - lstart) / CLOCKS_PER_SEC << " Sekunden"
              << std::endl;

    std::cout << std::endl;

    vstart = clock();
    for (int j = 0; j < N; ++j) {
        v.insert(v.end(), 0);
    }
    vstop = clock();

    lstart = clock();
    for (int k = 0; k < N; ++k) {
        l.insert(l.end(), 0);
    }
    lstop = clock();

    std::cout << "Insert at Vector.end:\t" << ((double) (vstop - vstart) / CLOCKS_PER_SEC)
              << " Sekunden." << std::endl;
    std::cout << "Insert at List.end:\t" << (double) (lstop - lstart) / CLOCKS_PER_SEC << " Sekunden"
              << std::endl;

    return 0;
}