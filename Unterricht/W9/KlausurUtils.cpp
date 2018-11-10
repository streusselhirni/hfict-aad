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

bool TestUtils::t1(std::vector<int> &v) {
	bool b = false;

  for (int i=0; i<v.size(); i++) {
    if (v.at(i) % 2 == 1) {
			if (b) {
				return false;
			}
		} else {
			b = true;
		}
	}

  return true;
}

bool TestUtils::t2(std::vector<int> &v) {
	bool b1 = true;
	bool b2 = false;

  for (int i=0; i<v.size(); i++) {
		if (!b2 && v.at(i) % 2 == 0) {
			b2 = true;
			b1 = true;
		}

		if (b1) {
			b1 = false;
			continue;
		}

		if (v.at(i) <= v.at(i-1)) {
			return false;
		}
	}

  return true;
}

bool TestUtils::t3(std::vector<int> &v) {
	std::set<int> values;
	for (int i=0; i<v.size(); i++) {
		values.insert(v.at(i));
	}
	return values.size() == v.size();
}
