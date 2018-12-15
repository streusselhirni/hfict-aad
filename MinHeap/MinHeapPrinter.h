#ifndef TREEPRINTER_H
#define TREEPRINTER_H
#include<iostream>
#include<vector>
#include"Trunk.h"

class MinHeapPrinter
{
private:
	static void showTrunks(Trunk* p);
	static int getLeftChildIndex(int index);
	static int getRightChildIndex(int index);
	
public:
	static void printVector(std::vector<int>& v, int size);
	static void printTree(std::vector<int>& v, int index, int size, Trunk* prev, bool isLeft);
};

#endif