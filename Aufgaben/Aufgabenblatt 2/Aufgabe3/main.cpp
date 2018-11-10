#include <iostream>
#include "StringUtil.h"

int main() {
    std::string denSatzSchoenerAussehenLassen,
            s10 = "Heidi Klum",
            s20 = "Helium Kid",
            s30 = "Axl Rose",
            s40 = "Oral sex",
            s50 = "Valentines day",
            s60 = "Satan deny evil",
            s70 = "Taylor Swift",
            s80 = "Ways to flirt";

    // Chose strings
    std::string s1 = s10,
            s2 = s20;

    std::cout << "Die Strings sind:" << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s1 << std::endl;

    if (!StringUtil::anagramCheck(s1, s2)) {
        denSatzSchoenerAussehenLassen = "keine ";
    }

    std::cout << "Die String sind " << denSatzSchoenerAussehenLassen << "Anagramme." << std::endl;

    return 0;
}