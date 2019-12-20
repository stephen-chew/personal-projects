/*
Stephen Chew (ssc6ae)
pre-lab 10, 11:00am
*/

#include "huffmanNode.h"
#include <iostream>

using namespace std;

// constructor
huffmanNode::huffmanNode(int frequency, char character){
	value = character;
	left = NULL;
	right = NULL;
	freq = frequency;
}
// destructor
huffmanNode::~huffmanNode(){
	delete left;
	delete right;
}

int huffmanNode::getFrequency() const{
	return freq;
}
char huffmanNode::getValue(){
	return value;
}
bool huffmanNode::operator<(const huffmanNode &x)const{
	return(this->getFrequency() < x.getFrequency());
}
bool huffmanNode::operator>(const huffmanNode &x)const{
	return(this->getFrequency() > x.getFrequency());
}
// char huffmanNode::getIdk() const{
// 	return idk;
// }