//
// Created by Nicolas Haenni on 13.09.18.
//

#include <iostream>
#include "StringUtil.h"

bool StringUtil::anagramCheck(std::string s1, std::string s2) {
    // Remove whitespaces between words (at cost of performance!)
    // Explanation see here:
    // https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
    s1.erase(remove_if(s1.begin(), s1.end(), isspace), s1.end());
    s2.erase(remove_if(s2.begin(), s2.end(), isspace), s2.end());

    // If string (without whitespaces) are not of equal length, they are not anagrams.
    if (s1.length() != s2.length()) return false;

    // Initialize arrays to count characters
    int *c1 = new int[26]();
    int *c2 = new int[26]();

    // Count characters
    for (int i = 0; i < s1.length(); i++) {
        c1[toupper(s1.at(i)) - 'A']++;
        c2[toupper(s2.at(i)) - 'A']++;
    }

    /*
    // For debugging: Print the two counting arrays above each other to compare
    std::cout << std::endl;

    for (int i = 0; i < 26; i++) {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 26; i++) {
        std::cout << c2[i] << " ";
    }
     */

    // Check if the same number of characters have been counted
    for (int i = 0; i < 26; i++) {
        if (c1[i] != c2[i]) return false;
    }
    return true;
}
