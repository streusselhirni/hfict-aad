#include <iostream>
#include <string>
#include <ctime>

int match(std::string t, std::string p) {
    for (unsigned long i = 0; i <= t.size() - p.size(); i++) {
        bool match = true;
        for (unsigned long j = 0; j < p.size(); j++) {
            if (t.at(i + j) != p.at(j)) {
                match = false;
                break;
            }
        }
        if (match) return static_cast<int>(i);
    }
    return -1;
}

int main() {
    clock_t start, stop;
    std::string t = "here is a simple example";
    std::string p = "simple";

    start = clock();
    std::cout << match(t, p) << std::endl;
    stop = clock();

    std::cout << "Laufzeit: " << static_cast<double>((stop-start)/CLOCKS_PER_SEC) << std::endl;

    return 0;
}