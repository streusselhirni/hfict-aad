#ifndef MINHEAP_H
#define MINHEAP_H
#include<vector>
#include<algorithm>
#include"MinHeapPrinter.h"

class MinHeap 
{
private:
	int m_capacity;
	int m_size;
	std::vector<int> m_vector; 
	
	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);
	int getParentIndex(int index);
	
	bool hasLeftChild(int index);
	bool hasRightChild(int index);
	bool hasParent(int index);
	
	int getLeftChildValue(int index);
	int getRightChildValue(int index);
	int getParentValue(int index);
	
	void swap(int index1, int index2);
	void ensureRequiredCapacity();
	
	void sinkDown();
	void swimUp();
	
public:
	MinHeap();
	virtual ~MinHeap();

	bool getMin(int& value);
	bool extractMin(int& value);
	void insert(int value);
	
	void print();
	void printTree();
};

#endif