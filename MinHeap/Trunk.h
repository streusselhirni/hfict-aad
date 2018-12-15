#ifndef TRUNK_H
#define TRUNK_H
#include<string>

struct Trunk
{
	Trunk* m_prev;
	std::string m_str;
	
	Trunk(Trunk* prev, std::string str)
	{
		this->m_prev = prev;
		this->m_str = str;
	}
};

#endif