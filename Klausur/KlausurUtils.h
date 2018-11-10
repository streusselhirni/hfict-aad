#ifndef KLAUSURUTILS_H
#define KLAUSURUTILS_H
#include<string>
#include<iostream>
#include<chrono>
#include<random>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<set>

class KlausurUtils
{
	private:
		static std::chrono::steady_clock::time_point m_timeStart;
		static std::map<std::string, std::vector<int>*> m_data;

	public:
		static void startTimer();
		static int stopTimer();
		static void generateRandValues(int qty, int lowLimit, int highLimit, std::vector<int>& data);
		static bool saveFile(std::string filepath, std::vector<int>& data);
		static bool loadFile(std::string filepath, std::vector<int>& data);
		static std::vector<int>* getDataVector(std::string filepath);
		static int getData(int idx, std::string filepath);
		static std::string boolToText(bool b);
};

class TestUtils
{
  public:
	  static bool t1(std::vector<int>& v);
	  static bool t2(std::vector<int>& v);
	  static bool t3(std::vector<int>& v);
};

#endif
