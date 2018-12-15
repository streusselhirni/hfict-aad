#include<iostream>
#include"MinHeap.h"

using namespace std;

void extractMin(MinHeap& h);

int main ()
{
	MinHeap h;
	
	h.insert(5);
	h.insert(2);
	h.insert(10);
	h.insert(8);
	h.insert(1);

	cout << "MinHeap Array:" << endl;
	h.print();
	cout << "MinHeap Tree:" << endl;
	h.printTree();	
	
	extractMin(h);
	extractMin(h);
	extractMin(h);
	extractMin(h);
	extractMin(h);
	extractMin(h);
	
	return 0;
}

void extractMin(MinHeap& h)
{
	int value;
	cout << endl;
	if (h.extractMin(value))
	{
		cout << "Extracted " << value << " from the MinHeap" << endl;
	}
	else
	{
		cout << "Could not extract from the MinHeap" << endl;
	}
	cout << "MinHeap Array:" << endl;
	h.print();
	cout << "MinHeap Tree:" << endl;
	h.printTree();
}