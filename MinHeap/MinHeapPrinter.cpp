#include"MinHeapPrinter.h"

void MinHeapPrinter::showTrunks(Trunk* p)
{
	if (p != 0)
	{
		showTrunks(p->m_prev);
		std::cout << p->m_str;
	}
}

int MinHeapPrinter::getLeftChildIndex(int index)
{
	return 2 * index + 1;
}

int MinHeapPrinter::getRightChildIndex(int index)
{
	return 2 * index + 2;
}

void MinHeapPrinter::printVector(std::vector<int>& v, int size)
{
	if (size <= 0) return;
	std::vector<int>::iterator heapEndIdx = v.end() + size - 1 - v.size();
	for (std::vector<int>::iterator i = v.begin(); i != heapEndIdx; i++)
	{
		std::cout << *i << ", ";
	}
	std::cout << *(heapEndIdx);
	std::cout << std::endl;
}

void MinHeapPrinter::printTree(std::vector<int>& v, int index, int size, Trunk* prev, bool isLeft)
{
	if (index < size)
	{	
		std::string prev_str = "    ";
		Trunk* trunk = new Trunk(prev, prev_str);

		printTree(v, getRightChildIndex(index), size, trunk, true);

		if (!prev)
			trunk->m_str = "---";
		else if (isLeft)
		{
			trunk->m_str = ".---";
			prev_str = "   |";
		}
		else
		{
			trunk->m_str = "`---";
			prev->m_str = prev_str;
		}

		showTrunks(trunk);
		std::cout << v[index];
		std::cout << std::endl;
		
		if (prev)
			prev->m_str = prev_str;
		trunk->m_str = "   |";

		printTree(v, getLeftChildIndex(index), size, trunk, false);
		
		delete trunk;
	}
}