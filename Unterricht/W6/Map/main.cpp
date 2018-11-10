#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> table;

    table[0] = "COLIN";
    table[8] = "THOMAS";
    table[4] = "DOMINIK";
    table[0] = "NICOLAS";

    table.insert(std::pair<int, std::string>(1, "BRUCE"));

    std::pair<std::map<int, std::string>::iterator, bool> returnValue;
    returnValue = table.insert(std::pair<int, std::string>(2, "PETER"));
    std::cout << "INSERT RESULT: " << returnValue.second << std::endl;

    std::map<int, std::string>::iterator it;

    for (it = table.begin(); it != table.end(); it++) {
        std::cout << it->first << " - " << it->second << std::endl;
    }

    return 0;

}