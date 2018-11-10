#include <iostream>
#include <ctime>

int main() {
    const int N = 10000;
    int *values = new int[N];
    int *result = new int[N];

    clock_t start, stop;

    for (int i = 0; i < N; i++) {
        values[i] = rand() % 10;
    }

    start = clock();
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += values[j];
        }
        result[i] = sum;
    }
    stop = clock();

    double time = (double) (stop - start) / CLOCKS_PER_SEC;
    std::cout << "Laufzeit: " << time << "s";
    return 0;
}