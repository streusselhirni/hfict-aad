#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class FastaReader {
public:
  static string read(const string & file, bool & success);
};

string FastaReader::read(const string & file, bool & success) {
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

int main(int argc, char **argv) {
  return 0;
}

