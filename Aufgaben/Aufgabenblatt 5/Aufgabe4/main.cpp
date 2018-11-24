//
// Created by Nicolas Haenni on 13.11.18.
//
#include <iostream>
#include <vector>

int calculate(std::string input) {
    std::vector<std::pair<char, int>> count(128);
    std::string                       lc     = input;
    int                               beauty = 0;

    std::transform(lc.begin(), lc.end(), lc.begin(), ::tolower);

    // Initialize all pairs in count array
    for (unsigned int i = 0; i < count.size(); i++) {
        count.at(i) = std::make_pair<char, int>(static_cast<char>(i), 0);
    }

    // Count all characters in string
    for (unsigned int i = 0; i < lc.size(); i++) {
        unsigned int asciCode = static_cast<unsigned int>(lc.at(i));
        count.at(asciCode).second = ++std::get<int>(count.at(asciCode));

    }

    // Sort count array
    std::sort(count.begin(), count.end(), [](std::pair<char, int> a, std::pair<char, int> b) {
        return std::get<int>(a) > std::get<int>(b);
    });

    for (unsigned int i = 0, max = 26; i < count.size(); i++) {
        int asciCode = static_cast<int>(std::get<char>(count.at(i)));
        // only characters between 97 and 122
        if (asciCode >= 97 && asciCode <= 122) {
            beauty += std::get<int>(count.at(i)) * max--;
        }
    }

    /*for (auto t : count) {
        std::cout << t.first << ", " << t.second << std::endl;
    }*/

    return beauty;
}

int main(int argc, char** argv) {

    std::string s1 = "ABBCCC";
    std::string s2 = "Sometimes test cases are hard to make up.";
    std::clock_t start, stop;
    
    
    std::cout << static_cast<int>('a') << ", " << static_cast<int>('z')<< std::endl;

    std::cout << "Schönheit der Zeichenkette \"" << s1 << "\":\t\n" << calculate(s1) << std::endl;
    
    start = clock();
    std::cout << "Schönheit der Zeichenkette \"" << s2 << "\":\t\n" << calculate(s2) << std::endl;
    stop = clock();
    std::cout << "Laufzeit: " << (double)(stop - start)/CLOCKS_PER_SEC << std::endl;

    return 0;
}