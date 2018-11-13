#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
#include<list>
#include"KlausurUtils.h"

using namespace std;

static const bool EXECUTE_PERFORMANCE_TEST_AUFGABE1 = true;

int getDataAufgabe1(int idx);
int getDataAufgabe3(int idx);

string aufgabe1_data = "Korrektur_Aufgabe1.dat";
string aufgabe1_samples = "Korrektur_Aufgabe1_Samples.dat";
string aufgabe2_data = "Aufgabe2.dat";
string aufgabe2_results = "Aufgabe2_Results.dat";
string aufgabe3_data = "Aufgabe3.dat";
string aufgabe3_samples = "Aufgabe3_Samples.dat";

bool methodeAufgabe1(int loadRecordsQty, int value)
{
    vector<int> values(loadRecordsQty - 1); // Pre-allocate size for performance

    for (int i = 0; i < loadRecordsQty - 1; i++) {
        values.at(i) = getDataAufgabe1(i);
    }

    for (int i : values) {
        if (i >= value) break;

        for (int j : values) {
            if (j >= value) break;
            if (i == j) continue;
            if (i + j == value) return true;
        }
    }
	
	return false;
}

int methodeAufgabe2(int n)
{
	// Abbruchbedingung
	if (n < 10) {
	    return n;
	}

    // Quersumme berechnen
    int quersumme = 0;
    int tmp = n;
    while (tmp > 0) {
        quersumme += (tmp % 10);
        tmp /= 10;
    }

    // Rekursiver Aufruf
	return methodeAufgabe2(quersumme);
}

vector<int> methodeAufgabe3(int loadRecordsQty)
{
    set<int> even, odd;

    for (int i = 0; i < loadRecordsQty; i++) {
        int tmp = getDataAufgabe3(i);

        if (tmp % 2 == 0) {
            even.insert(even.end(), tmp);
        }
        else {
            odd.insert(odd.end(), tmp);
        }
    }

    auto *res = new vector<int>;

    for (set<int>::iterator it_odd = odd.begin(); it_odd != odd.end(); it_odd++) {
        res->push_back(*it_odd);
    }
    for (set<int>::iterator it_even = even.begin(); it_even != even.end(); it_even++) {
        res->push_back(*it_even);
    }

	return *(res);
}

int main ()
{
	// Access all Files one time to have the data cached
	getDataAufgabe1(0);
	// Variables used later
	bool calculatedBoolResult;

	/*********************************************************
	 * Automatic Checks of Aufgabe 1 - Do not change this code below
	 *********************************************************/

	cout << "AUFGABE 1 - RESULTATE" << endl;

	// Kleine Datenmenge
	int sampleDataAufgabe1 = KlausurUtils::getData(0, aufgabe1_samples);
	calculatedBoolResult = methodeAufgabe1(100, sampleDataAufgabe1);
	cout << "[CHECK -> " << KlausurUtils::boolToText(calculatedBoolResult)
	     << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
		 << (calculatedBoolResult ? "true" : "false") << "' - Expected Result = 'true'" << endl;
    sampleDataAufgabe1 = KlausurUtils::getData(1, aufgabe1_samples);
	calculatedBoolResult = methodeAufgabe1(100, sampleDataAufgabe1);
	cout << "[CHECK -> " << KlausurUtils::boolToText(!calculatedBoolResult)
	     << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
		 << (calculatedBoolResult ? "true" : "false") << "' - Expected Result = 'false'" << endl;

	// Grosse Datenmenge (mit Zeitmessung)
	if (EXECUTE_PERFORMANCE_TEST_AUFGABE1)
	{
		KlausurUtils::startTimer();
		sampleDataAufgabe1 = KlausurUtils::getData(2, aufgabe1_samples);
		calculatedBoolResult = methodeAufgabe1(50000, sampleDataAufgabe1);
		cout << "[CHECK -> " << KlausurUtils::boolToText(calculatedBoolResult)
			 << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
			 << (calculatedBoolResult ? "true" : "false") << "' - Expected Result = 'true'" << endl;
		sampleDataAufgabe1 = KlausurUtils::getData(3, aufgabe1_samples);
		calculatedBoolResult = methodeAufgabe1(50000, sampleDataAufgabe1);
		cout << "[CHECK -> " << KlausurUtils::boolToText(!calculatedBoolResult)
			 << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
			 << (calculatedBoolResult ? "true" : "false") << "' - Expected Result = 'false'" << endl;
		cout << "Expected Performance = t < 100ms | Effective Time Diff = " << KlausurUtils::stopTimer() << "ms" << endl;
	}
	else
	{
		cout << " !!! PERFORMANCE TESTS AUFGABE 1 HAS BEEN SKIPPED !!! " << endl;
	}

	/*********************************************************
	 * Automatic Checks of Aufgabe 2 - Do not change this code below
	 *********************************************************/

	cout << endl << "AUFGABE 2 - RESULTATE" << endl;

	vector<int>* v = KlausurUtils::getDataVector(aufgabe2_data);

	for (vector<int>::iterator it = v->begin(); it < v->end(); it++)
	{
		int elementIdx = distance(v->begin(), it);
		int result = methodeAufgabe2(*it);
		if (result == KlausurUtils::getData(elementIdx, aufgabe2_results))
		{
			cout << "[CHECK -> PASSED]";
		}
		else
		{
			cout << "[CHECK -> FAILED]";
		}
		cout << " - Calculated Result for methodeAufgabe2(" << *it << ") = '" << result << "' - Expected Result = '"
		     << KlausurUtils::getData(elementIdx, aufgabe2_results) << "'" << endl;
	}

	/*********************************************************
	 * Automatic Checks of Aufgabe 3 - Do not change this code below
	 *********************************************************/

	cout << endl << "AUFGABE 3 - RESULTATE" << endl;

	// Kleine Datenmenge
  vector<int>* sa3 = KlausurUtils::getDataVector(aufgabe3_samples);
  vector<int> result = methodeAufgabe3(sa3->size());
	cout << "Small dataset Aufgabe 3" << endl;
	cout << "[CHECK -> " << ((result.size() == 100) ? "PASSED" : "FAILED") << "] - Size of dataset" << endl;
	cout << "[CHECK -> " << (TestUtils::t1(result) ? "PASSED" : "FAILED") << "] - Correct split" << endl;
	cout << "[CHECK -> " << (TestUtils::t2(result) ? "PASSED" : "FAILED") << "] - Order of values" << endl;
	cout << "[CHECK -> " << (TestUtils::t3(result) ? "PASSED" : "FAILED") << "] - Duplicate check" << endl;
	delete sa3;

	if (EXECUTE_PERFORMANCE_TEST_AUFGABE1)
	{
		vector<int>* ba3 = KlausurUtils::getDataVector(aufgabe3_data);
		KlausurUtils::startTimer();		
		result = methodeAufgabe3(ba3->size());
		cout << "Big dataset Aufgabe 3" << endl;
		cout << "[CHECK -> " << ((result.size() == 50001) ? "PASSED" : "FAILED") << "] - Size of dataset" << endl;
		cout << "[CHECK -> " << (TestUtils::t1(result) ? "PASSED" : "FAILED") << "] - Correct split" << endl;
		cout << "[CHECK -> " << (TestUtils::t2(result) ? "PASSED" : "FAILED") << "] - Order of values" << endl;
		cout << "[CHECK -> " << (TestUtils::t3(result) ? "PASSED" : "FAILED") << "] - Duplicate check" << endl;
		cout << "Expected Performance = t < 10000ms | Effective Time Diff = " << KlausurUtils::stopTimer() << "ms" << endl;
		delete ba3;
	}
	else
	{
		cout << " !!! PERFORMANCE TESTS AUFGABE 3 HAS BEEN SKIPPED !!! " << endl;
	}

	return 0;
}

int getDataAufgabe1(int idx)
{
	return KlausurUtils::getData(idx, aufgabe1_data);
}

int getDataAufgabe3(int idx)
{
	return KlausurUtils::getData(idx, aufgabe3_data);
}