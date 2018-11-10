//
// Created by Nicolas Haenni on 24.08.18.
//
#include <iostream>
#include <array>
#include "StringUtil.h"

/**
 * Gibt true zurück, wenn der String Buchstaben enthält, die nur einmal vorkommen
 * und false, falls mindestens ein Buchstabe mehrmals vorkommt.
 * @param {string} s - Zu analysierender String
 * @return {bool} - True falls alle Buchstaben einzigartig sind
 */
bool StringUtil::checkUniqueness(std::string &s) {
    int anzahl[26] = {0}; // Array zum zählen der einzelnen Buchstaben

    // Alle Buchstaben im String in Großbuchstaben konvertieren
    for (auto &c : s) {
        c = (char) (std::toupper(c));
    }

    // Buchstaben zählen
    for (int i = 0; i < s.length(); i++) {

        // Falls s[i] ein Buchstabe ist
        if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25) {
            // Zähle entsprechende Stelle im Array hoch ('A' - 'A' == 0 && 'Z' - 'A' == 25)
            anzahl[s.at((unsigned long)(i)) - 'A']++;
            // Falls Buchstabe mehr als einmal
            if (anzahl[s.at((unsigned long)(i)) - 'A'] > 1) return false;
        }
    }

    /**
     * Lösung mit C++ Array um zu prüfung, ob die if-Abfrage korrekt ist.
     * Der C++ Array unterstützt den Zugriff mit .at() und wirft so einen Error, wenn der Index out-of-bounds
     * ist. Sonderzeichen würden dies auslösen. Dank dieser Variante konnte ich prüfen, dass keine Errors
     * geworfen werden, auch wenn Sonderzeichen enthalten sind. Es gibt Errors, wenn die if-Abfrage weggelassen
     * wird.
     */
    /*
    std::array<int, 26> cppArray = {0};
    for (int i = 0; i < s.length(); i++) {

        // Falls s[i] ein Buchstabe ist
        if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25) {
            // Zähle entsprechende Stelle im Array hoch ('A' - 'A' == 0 && 'Z' - 'A' == 25)
            cppArray.at(s.at(i) - 'A')++;
            // Falls Buchstabe mehr als einmal
            if (cppArray.at(s.at(i) - 'A') > 1) return false;
        }
    }
     */

    return true;
}
