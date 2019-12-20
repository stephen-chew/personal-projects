/*
Stephen Chew (ssc6ae)
pre-lab 10, 11:00am
*/

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>


#include "huffmanNode.h"
using namespace std;

class binary_heap {
public:
    binary_heap();
    //binary_heap(vector<int> vec);
    ~binary_heap();

    void insert(huffmanNode *x);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<huffmanNode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif