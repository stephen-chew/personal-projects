/*
Stephen Chew
Last Edited: 12-25-2019
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
	bool operator<(const huffmanNode &x)const;
	bool operator>(const huffmanNode &x)const;

};
#endif