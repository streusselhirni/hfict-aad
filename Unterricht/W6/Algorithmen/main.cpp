#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>

void unique() {
    std::cout << "===== Unique Numbers =====" << std::endl;
    std::mt19937_64 gen;
    std::uniform_int_distribution<int> dist(0,10000);
    const int N = 10000;
    std::vector<int> v;
    for (int i = 0; i < N; ++i) {
        v.insert(v.end(), dist(gen));
    }

    // Lösung Set
    std::set<int> s;

    for (int i : v) {
        s.insert(i);
    }

    std::cout << "Anzahl Zahlen im Set: " << s.size() << std::endl;


    // Lösung mit std::unique
    std::sort(v.begin(), v.end());
    std::vector<int>::iterator it;
    it = std::unique(v.begin(), v.end());

    v.resize((unsigned int)(std::distance(v.begin(), it)));

    std::cout << "Anzahl nach std::unigue(): " << v.size() << std::endl;
}

void even() {
    std::cout << "===== Remove Even =====" << std::endl;
    std::mt19937_64 gen;
    std::uniform_int_distribution<int> dist(0,10000);
    const int N = 10000;
    std::vector<int> v;
    for (int i = 0; i < N; ++i) {
        v.insert(v.end(), dist(gen));
    }

    auto it = std::remove_if(v.begin(), v.end(), [](int a) { return (a % 2 == 0); } );
    v.resize((unsigned int)(std::distance(v.begin(), it)));

    std::cout << "Neue Größe: " << v.size() << std::endl;
    std::cout << std::endl;
}

void shuffle() {
    std::cout << "===== Shuffle =====" << std::endl;
    const int N = 50;
    std::vector<int> v;
    std::mt19937_64 gen;
    std::uniform_int_distribution<int> dist(0,100);
    for (int i = 0; i < N; ++i) {
        v.insert(v.end(), dist(gen));
    }

    std::cout << "Original:" << std::endl;
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::shuffle(v.begin(), v.end(), std::default_random_engine(12345));

    std::cout << "Nach Shuffle:" << std::endl;
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}


int main() {
    unique();
    even();
    shuffle();

    return 0;
}