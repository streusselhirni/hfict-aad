#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

string sampleSequence(int n) {
    string   s       = "";
    char     alpha[] = {'A', 'C', 'G', 'T'};
    for (int i       = 0; i < n; i++) {
        s += alpha[rand() % 4];
    }
    return s;
}

/*class FastaReader {
public:
  static string read(const string & file, bool & success);
};*/

/*string FastaReader::read(const string & file, bool & success) {
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
}*/

/*
int match(string t, string p) {
  for (int i=0; i<t.size()-p.size()+1; i++) {
    if (p[0] != t[i]) continue;
    bool match = true;
    for (int j=0; j<p.size(); j++) {
      if (p[j] != t[i+j]) {
        match = false;
        break;
      }
    }
    if (match) return i;
  }
  return -1;
}
*/

int match(string t, string p) {
    // create lookup table
    map<char, long> lookuptable;
    // fill up table
    for (int        i = 0; i < p.size() - 1; i++) {
        lookuptable[p.at(i)] = p.size() - 1 - i;
    }

    int startIndex = 0;
    int pIndex     = p.size() - 1;
    while (startIndex <= t.size() - p.size()) {
        // compare from right
        int  tIndex = startIndex + pIndex;
        char pCh    = p.at(pIndex);
        char tCh    = t.at(tIndex);
        if (pCh != tCh) {
            int shift;
            // if not in table -> shift pattern.size()
            if (lookuptable.find(tCh) != lookuptable.end()) {
                shift = lookuptable[tCh];
            }
            else {
                shift = p.size();
            }
            pIndex = p.size() - 1;
            startIndex += shift;
        }
        else {
            if (pIndex == 0) {
                return startIndex;
            }
            pIndex--;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    bool   success;
    //string t = FastaReader::read("mm_ref_GRCm38.p4_chr17.fa", success);
//  string t = sampleSequence(200000000);
    //cout << success << endl;
//  string p = FastaReader::read("XY_gene.fa", success);
//  cout << success << endl;
//  string p = sampleSequence(100);
    //cout << p << endl;
//    string t = "er sagte abrakadabra aber";
//    string p = "aber";
    string t = "here is a simple example";
    string p = "example";

    clock_t start, stop;
    start = clock();
    cout << match(t, p) << endl;
    stop = clock();
    cout << "Time used: " << (double) (stop - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
