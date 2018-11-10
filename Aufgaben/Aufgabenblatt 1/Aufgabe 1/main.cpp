#include <iostream>
#include <ctime>

/**
 * Aufgabe 1:
 * Welche Laufzeit hat der folgende Code?
 *
 * Laufzeit von O(2n), also linear.
 * Es muss zwei mal durch das gesamte Array geloopt werden. Folglich wird mit jeden zusätzlichen Element die
 * doppelte Zeit, die für ein Element benötigt wird, "dazubenötigt".
 */
void foo(int *array, int size) {
    int sum = 0;
    int product = 1;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    for (int i = 0; i < size; i++) {
        product *= array[i];
    }
    std::cout << sum << ", " << product << std::endl;
}

/**
 * Helper-Funktion um Funktion foo aus Aufgabe 1 laufen zu lassen. Generiert einen Array, der in jedem Element
 * seinen Index + 1 als Wert hat (arr[0] = 1, arr[1] = 2, etc.)
 * @param {int} size - Größe des Arrays
 * @return {int[]}
 */
int *generateArray(int size) {
    int *arr = new int[size];
    for (int i(1); i <= size; i++) {
        arr[i - 1] = i;
    }
    return arr;
}


int main() {
    std::cout << "Aufgabe 1\n#####################" << std::endl;
    int size(10);
    clock_t start, stop;
    int *arr = generateArray(size);
    start = clock();
    foo(arr, size);
    stop = clock();
    std::cout << "Zeit: " << (double) (stop - start) / CLOCKS_PER_SEC << " Sekunden" << std::endl;

    return 0;
}