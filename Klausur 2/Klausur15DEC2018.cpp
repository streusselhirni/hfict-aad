#include<iostream>
#include<cmath>
#include<vector>
#include<list>
#include<algorithm>
#include"KlausurUtils.h"

using namespace std;

// FUEGEN SIE FALLS NOETIG ABSOLUTE PFADE EIN
string aufgabe1_data = "Aufgabe1.dat";
string aufgabe1_results = "Aufgabe1_Results.dat";
string aufgabe2_samples = "Aufgabe2_Samples.dat";
string aufgabe2_results = "Aufgabe2_Results.dat";
string aufgabe3_data = "Aufgabe3.dat";
string aufgabe3_results = "Aufgabe3_Results.dat";

void methodeAufgabe1(vector<int>& input, vector<int>& output, int idx)
{
	// IMPLEMENT YOUR SOLUTION HERE
	// USE VECTOR<INT> OUTPUT TO RETURN DATA (NO RETURN COMMAND REQUIRED)
}

string methodeAufgabe2(int idx)
{
	// IMPLEMENT YOUR SOLUTION HERE
	return ""; // REPLACE WITH CORRECT RETURN COMMAND
}

vector<int> methodeAufgabe3(vector<vector<int>>& data) 
{
	// IMPLEMENT YOUR SOLUTION HERE
	return vector<int>(); // REPLACE WITH CORRECT RETURN COMMAND
}

int main ()
{
	/*********************************************************
	 * Aufgabe 1
	 *********************************************************/

	cout << "AUFGABE 1 - RESULTATE" << endl;
	cout << "=====================" << endl;
	vector<int> data1 = *(KlausurUtils::getDataVector(aufgabe1_data));
	vector<int> results1 = *(KlausurUtils::getDataVector(aufgabe1_results));
	vector<int> output = vector<int>(0);
	methodeAufgabe1(data1, output, 0);
	cout << "[CHECK -> " << (output.size() == results1.size() && output == results1 ? "PASSED" : "FAILED")
	     << "] - Size of Data Vector: '" << data1.size() 
	     << "' - Size of Result Vector: '" << results1.size() << "'" << endl
	     << "                 " 		 
		 << " - First 10 and last 10 items in calculated result vector: " 
		 << KlausurUtils::vectorToString(output, 10, 10) << endl
	     << "                 " 
		 << " - First 10 and last 10 items in expected result vector: "
		 << KlausurUtils::vectorToString(results1, 10, 10) << endl;		 
	
	/*********************************************************
	 * Aufgabe 2
	 *********************************************************/

	cout << endl << endl << "AUFGABE 2 - RESULTATE" << endl;
	cout << "=====================" << endl;
	vector<int> samples2 = *(KlausurUtils::getDataVector(aufgabe2_samples));
	vector<vector<int>> results2 = KlausurUtils::get2dDataVector(aufgabe2_results);
	int i2 = 0;
	for (int& data2 : samples2)
	{
		string output2 = methodeAufgabe2(data2);
		vector<int> v2 = results2[i2++];
		string result2 = string(v2.begin(), v2.end());
	cout << "[CHECK -> " << ((output2 == result2) ? "PASSED" : "FAILED") 
	     << "] - Method Output: '" << output2 
	     << "' - Expected Result: '" << result2 << "'" << endl;
	}
	
	/*********************************************************
	 * Aufgabe 3
	 *********************************************************/
	 
	cout << endl << endl << "AUFGABE 3 - RESULTATE" << endl;
	cout << "=====================" << endl;	
	vector<vector<int>> data3 = KlausurUtils::get2dDataVector(aufgabe3_data);
	vector<int> result3 = *(KlausurUtils::getDataVector(aufgabe3_results));
	vector<int> output3 = methodeAufgabe3(data3);
	cout << "[CHECK -> " << ((output3 == result3) ? "PASSED" : "FAILED") 
	     << "] - Method Output: " << KlausurUtils::vectorToString(output3) << endl
		 << "                  "
	     << "- Expected Result: " << KlausurUtils::vectorToString(result3) << endl;	
	
	return 0;
}