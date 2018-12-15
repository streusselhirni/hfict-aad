#ifndef KLAUSURUTILS_H
#define KLAUSURUTILS_H
#include<string>
#include<iostream>
#include<chrono>
#include<random>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<climits>

static const int MULTI_DIM_VECTOR_DELIMITOR = -1;

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
		static void save2dVectorFile(std::string filepath, std::vector<std::vector<int>>& v2d);
		static bool loadFile(std::string filepath, std::vector<int>& data);
		static std::vector<int>* getDataVector(std::string filepath);
		static std::vector<std::vector<int>> get2dDataVector(std::string filepath);
		static int getData(int idx, std::string filepath);
		static std::string boolToText(bool b);
		static std::string vectorToString(std::vector<int>& v, int startLimit = INT_MAX, int endLimit = INT_MAX);
};

#endif
