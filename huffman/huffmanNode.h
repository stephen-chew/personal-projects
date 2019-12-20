/*
Stephen Chew (ssc6ae)
pre-lab 10, 11:00am
*/

#include "binary_heap.h"

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;

class huffmanNode{
public:
	huffmanNode(int frequency, char character);
	~huffmanNode();
	huffmanNode *left, *right;
	int freq;
	char value;
	int getFrequency() const;
	char getValue();

	// UHH DOES THIS WORK????? used in percolate of binary_heap
	bool operator<(const huffmanNode &x)const;
	bool operator>(const huffmanNode &x)const;

	// char getIdk() const;
};
#endif