#include"MinHeap.h"

MinHeap::MinHeap() : m_capacity(10), m_size(0), m_vector(m_capacity) {}

MinHeap::~MinHeap() {}

int MinHeap::getLeftChildIndex(int index)
{
	return 2 * index + 1;
}

int MinHeap::getRightChildIndex(int index)
{
	return 2 * index + 2;
}

int MinHeap::getParentIndex(int index)
{
	return (index - 1) / 2;
}

bool MinHeap::hasLeftChild(int index)
{
	return getLeftChildIndex(index) < m_size;
}

bool MinHeap::hasRightChild(int index)
{
	return getRightChildIndex(index) < m_size;
}

bool MinHeap::hasParent(int index)
{
	return getParentIndex(index) >= 0;
}

int MinHeap::getLeftChildValue(int index)
{
	return m_vector[getLeftChildIndex(index)];
}

int MinHeap::getRightChildValue(int index)
{
	return m_vector[getRightChildIndex(index)];
}

int MinHeap::getParentValue(int index)
{
	return m_vector[getParentIndex(index)];
}

void MinHeap::swap(int index1, int index2)
{
	std::iter_swap(m_vector.begin() + index1, 
				   m_vector.begin() + index2);
}

void MinHeap::ensureRequiredCapacity()
{
	if (m_size == m_capacity)
	{
		m_vector.insert(m_vector.end(), m_capacity);
		m_capacity *= 2;
	}
}

bool MinHeap::getMin(int& value)
{
	if (m_size <= 0) return false;
	value = m_vector[0];
	return true;
}

bool MinHeap::extractMin(int& value)
{
	if (m_size <= 0) return false;
	value = m_vector[0];
	MinHeap::swap(0, m_size - 1);
	m_size --;
	sinkDown();
	return true;
}

void MinHeap::insert(int value)
{
	ensureRequiredCapacity();
	m_vector[m_size] = value;
	m_size ++;
	swimUp();
}

void MinHeap::sinkDown()
{
	int index = 0;
	while (hasLeftChild(index))
	{
		// Identify the smaller Child of both attached to the node currently processed
		int smallerChildIndex = getLeftChildIndex(index);
		if (hasRightChild(index) && 
		    getRightChildValue(index) < getLeftChildValue(index))
		{
			smallerChildIndex = getRightChildIndex(index);
		}
		
		// If the currently processed element value is smaller than the smallest Child value then the element is at the right spot within the heap
		if (m_vector[index] < m_vector[smallerChildIndex])
		{
			break;
		}
		else
		{
			// Still bigger -> swap with smallest Child
			MinHeap::swap(index, smallerChildIndex);
			index = smallerChildIndex;
		}
	}
}

void MinHeap::swimUp()
{
	int index = m_size - 1;
	while (hasParent(index) && getParentValue(index) > m_vector[index])
	{
		MinHeap::swap(getParentIndex(index), index);
		index = getParentIndex(index);
	}
}

void MinHeap::print()
{
	MinHeapPrinter::printVector(m_vector, m_size);
}

void MinHeap::printTree()
{
	MinHeapPrinter::printTree(m_vector, 0, m_size, 0, false);
}