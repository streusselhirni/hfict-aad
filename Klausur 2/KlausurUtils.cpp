#include"KlausurUtils.h"

std::chrono::steady_clock::time_point KlausurUtils::m_timeStart;

std::map<std::string, std::vector<int>*> KlausurUtils::m_data;

bool KlausurUtils::saveFile(std::string filepath, std::vector<int>& data)
{
	std::ofstream fs(filepath);
	if (!fs) {
		std::cout << "The file '" << filepath << "' could not be opened !!!" << std::endl;
		return false;
	}

	std::ostream_iterator<int> out_it (fs, " ");
	std::copy(data.begin(), data.end(), out_it);
	return true;
}

void KlausurUtils::save2dVectorFile(std::string filepath, std::vector<std::vector<int>>& v2d)
{
	int count = 0;
	std::vector<int> vFlat(0);
	for (std::vector<int>& v : v2d)
	{
		if (count++ > 0)
			vFlat.push_back(MULTI_DIM_VECTOR_DELIMITOR);
		for (int& value : v)
		{
			vFlat.push_back(value);
		}
	}
	
	saveFile(filepath, vFlat);
}

bool KlausurUtils::loadFile(std::string filepath, std::vector<int>& data)
{
  std::ifstream fs(filepath);
  if (!fs) {
    std::cout << "The file '" << filepath << "' could not be opened !!!" << std::endl;
	return false;
  }

  std::istream_iterator<int> in_it (fs);
  std::istream_iterator<int> eos;

  data.clear();
  std::for_each(in_it,eos,[&data](const int& n){ data.push_back(n); });

  std::cout << "Loaded " << data.size() << " values from file " << filepath << std::endl;

  return true;
}

void KlausurUtils::startTimer()
{
	m_timeStart = std::chrono::steady_clock::now();
}

int KlausurUtils::stopTimer()
{
	auto fp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_timeStart);
	return fp_ms.count();
}

void KlausurUtils::generateRandValues(int qty, int lowLimit, int highLimit, std::vector<int>& data)
{
	// Setup Random Generator providing random number within the range 0..1000
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine randEngine(seed);
	std::uniform_int_distribution<> randDistributor(lowLimit, highLimit);
	auto distributedRandGen = [&randDistributor, &randEngine]()
								{
									return randDistributor(randEngine);
								};

	// Insert Elements and generate Data
	data.insert(data.end(), qty, 0);
	generate(data.begin(), data.end(), distributedRandGen);
}

std::vector<int>* KlausurUtils::getDataVector(std::string filepath)
{
	// Check if data cache already exists
	auto it = KlausurUtils::m_data.find(filepath);
	if (it == KlausurUtils::m_data.end())
	{
		// Create new vector for chache in the map
		std::cout << "Create Cache for " << filepath << "..." << std::endl;
		KlausurUtils::m_data[filepath] = new std::vector<int>(0);
	}

	// Open file and transfer int values to the cache
	std::vector<int>* v = KlausurUtils::m_data[filepath];
	if (v->size() <= 0)
	{
		std::cout << "Load File " << filepath << "..." << std::endl;
		loadFile(filepath, *v);
	}
	return v;
}

std::vector<std::vector<int>> KlausurUtils::get2dDataVector(std::string filepath)
{
	std::vector<int> flatData = *(KlausurUtils::getDataVector(filepath));
	
	// Convert flat Vector into a two dimensional Vector
	std::vector<std::vector<int>> v2d;
	std::vector<int> v;
	
	for (int& value : flatData)
	{
		if (value == MULTI_DIM_VECTOR_DELIMITOR)
		{
			v2d.push_back(v);
			v =	std::vector<int>();
		}
		else
		{
			v.push_back(value);
		}
	}
	v2d.push_back(v);
	
	return v2d;
}

int KlausurUtils::getData(int idx, std::string filepath)
{
	std::vector<int>* v = KlausurUtils::getDataVector(filepath);

	if (idx < v->size())
		return (*v)[idx];
	else
		return 0;
}

std::string KlausurUtils::boolToText(bool b)
{
	return b == true ? "PASSED" : "FAILED";
}

std::string KlausurUtils::vectorToString(std::vector<int>& v, int startLimit, int endLimit)
{
	std::stringstream ss;
	bool fill = true;
	int endOffset = v.size() - endLimit - 1;
	ss << "{";
	int i = 0;
	for (int(i) = 0; i < v.size(); i++)
	{
		if (i < startLimit || i > endOffset)
		{
			ss << v[i];
			if (i < v.size() - 1)
				ss << ", ";
		}
		else if (fill)
		{
			ss << " ... ";
			if (i < v.size() - 1 && endLimit != 0)
				ss << ", ";
			fill = false;
		}
	}
	ss << "}";
	
	return ss.str();
}