#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

class FastaReader {
public:
    static string read(const string &file, bool &success);
};

string FastaReader::read(const string &file, bool &success) {
    ifstream fs(file);
    if (!fs) {
        success = false;
        return "";
    }
    success = true;
    string result = "", line;
    while (getline(fs, line)) {
        if (line.at(0) != '>') {
            result += line;
        }
    }
    return result;
}

char analyzeSequence(string sequence) {
    // return the nucleotide which appears most
    int countA(0), countG(0), countC(0), countT(0);

    for (char ch : sequence) {
        if (toupper(ch) == 'A') countA++;
        if (toupper(ch) == 'G') countG++;
        if (toupper(ch) == 'C') countC++;
        if (toupper(ch) == 'T') countT++;
    }

    if (countA > countC && countA > countG && countA > countT) return 'A';
    if (countC > countA && countC > countG && countC > countT) return 'C';
    if (countT > countC && countT > countG && countT > countA) return 'T';
    if (countG > countC && countG > countA && countG > countT) return 'G';

    return 0;
}

int main(int argc, char **argv) {

    // TASKS
    // 1. Read the sample.fa file
    // 2. Print the length of the sample sequence
    // 3. Implement the method analyzeSequence and find out which nucleotide
    //    appears most
    // 4. Read the Human Chromosome 1 Sequence (download the file from NCBI)
    // 5. Print the length of the sequence
    // 6. Run your algorithm on the human sequence

    FastaReader reader;
    bool success(false);
    std::string file("/Users/nicolashaenni/Education/HF-ICT/AAD/Unterricht/W1/Ex2/hs_ref_GRCh38.p12_chr1.fa");
    std::map<char, long int> characters;
    clock_t start_total, stop_total, start, stop;
    
    start_total = clock();

    // Read file
    std::string sequence(FastaReader::read(file, success));

    start = clock();
    char ch = analyzeSequence(sequence);
    stop = clock();

    std::cout << "Häufigster Buchstabe: " << ch << std::endl;
    
    stop_total = clock();
    std::cout << "Zeit für Suche: " << (double) (stop - start) / CLOCKS_PER_SEC << " Sekunden";
    std::cout << "Zeit total: " << (double)(stop_total - start_total) / CLOCKS_PER_SEC << " Sekunden" << std::endl;
    return 0;
}
