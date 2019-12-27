/*
Stephen Chew
Last Edited: 12-25-2019
*/

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>


#include "huffmanNode.h"
using namespace std;

class binary_heap {
public:
    binary_heap();
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