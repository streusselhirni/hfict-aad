#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

string randomString(int size) {
    string s = "";
    for (int i = 0; i < size; i++) {
        s += 'A' + rand() % 24;
    }
    s += "ZY";
    return s;
}

char getFirstSingleChar(string s) {
    for (int i(0); i < s.length(); i++) {
        char ch = s[i];
        long c = count(s.begin(), s.end(), ch); // for (int j(0); i < s.length(); j++)
        if (c == 1) {
            return ch;
        }
    }
    return 0;
}

char getFirstSingleChar2(string s) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    char buchstabe;
    int pos;
    for (int i(0); i < s.length(); i++) {
        unsigned long count(0);
        for (int j(0); j < alphabet.length(); j++) {
            char curr = s.at(i);
            char c = alphabet.at(j);
            if (c == curr) count++;
        }
        if (count == 1) {
            buchstabe = s.at(i);
            pos = i;
        }
    }
    return buchstabe;
}

char getFirstSingleChar3(string s) {
    int counter[26] = {0};
    int position[26] = {0};
    for (int i(0); i < s.length(); i++) {
        char c = s.at(i);
        int pos = c - 'A';
        counter[pos]++;
        if (counter[pos] == 1) {
            position[pos] = i;
        } else {
            position[pos] = -1;
        }
    }
    long int result(s.length() + 1);
    char ch;
    for (int i(0); i < 26; i++) {
        if (counter[i] == 1) {
            if (result > position[i]) {
                result = position[i];
                ch = 'A' + i;
            }
        }
    }
    return ch;
}

int main() {
    clock_t start, stop;

    cout << "Erster Buchstabe: ";
    // Zeiten gemessen mit MacBook Pro Intel Core i7 8.Gen (2018)
    // 1.623700 Sekunden mit 20000      mit Var.1
    // 0.002544 Sekunden mit 20000      mit Var.2
    // 25.17070 Sekunden mit 100000     mit Var.1
    // 0.012045 Sekunden mit 100000     mit Var.2
    // 0.109659 Sekunden mit 1000000    mit Var.2
    // 7.581910 Sekunden mit 1000000000 mit Var.3
    string s = randomString(1000000000);
    start = clock();
    cout << getFirstSingleChar3(s) << endl;
    stop = clock();
    cout << "Zeit: " << (double) (stop - start) / CLOCKS_PER_SEC << " Sekunden.";
    return 0;
}